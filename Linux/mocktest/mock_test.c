#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct 
{
	char validFiles[50];
	int filesDescriptor;
} data;

typedef struct
{
	data files[100];
	int fileCount;
} fileInfo;

int sum = 0,n = 0;
pthread_mutex_t own;

fileInfo* fileValidation(int argc, char** argv);
int files_fd(char* fileName);
void* fileRandSequeGene(void* fileinfo);
void* fileSeqGen(void* filedata);
void* wordCount(void* file);


int main(int argc, char** argv) {
	if (argc < 2 || argc == 2) {
		printf("\nAt least provide one file\n");
		return 1;
	}

	if (argv[1][0] != '-') {
		errno = 22;
		fprintf(stderr,"Provide the word width\n");
		perror("Error");
		return errno;
	}

	int status = 1;
	sscanf(argv[1], "-%d", &n);

	if( n <= 0){
		fprintf(stderr,"word width cannot be <= 0\n");
		errno = 22;
		perror("Error");
		return errno;
	}

	sem_t* child = sem_open("child", O_CREAT,0666,0);
	if(child == SEM_FAILED){
		perror("sem_open");
		return errno;
	}


	int p_fd[2];
	if(pipe(p_fd) == -1){
		perror("pipe");
		return errno;
	}
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		return errno;
	}

	if (pid == 0) {
		sem_wait(child);
        
		close(p_fd[1]);
		printf("\nchild started\n");
		fileInfo files;
		read(p_fd[0],&files,sizeof(fileInfo));
		pthread_mutex_init(&own,NULL);
		pthread_t file_wc[files.fileCount];
		for(int i=0; i<files.fileCount; i++){
			pthread_create(&file_wc[i],NULL,wordCount,&files.files[i]);
			pthread_join(file_wc[i],NULL);
        }
        pthread_mutex_destroy(&own);
		close(p_fd[1]);
		printf("\nchild ended..\n");
		//sem_post(child);
	} 
	else {
		//close(p_fd[0]);

		printf("\nParent Started\n");
		fileInfo* fileinfo = fileValidation(argc , argv);

		pthread_t th[fileinfo->fileCount];
		for(int i=0; i<fileinfo->fileCount; i++){
			pthread_create(&th[i],NULL,fileSeqGen,&fileinfo->files[i]);

			pthread_join(th[i],NULL);
		}

		printf("\nParent Ended\n");
		write(p_fd[1],fileinfo,sizeof(fileInfo));
		close(p_fd[1]);
		sem_post(child);
		waitpid(pid, &status, 0);
        sem_unlink("child");
        
	}

	if(pid == 0)
		printf("\nwordCount -> %d\n",sum);
	return 0;
}

fileInfo* fileValidation(int argc, char** argv) {
	fileInfo* fileinfo = (fileInfo*)malloc(sizeof(fileInfo));
	if (fileinfo == NULL) {
		errno = 12;
		fprintf(stderr, "%s", strerror(errno));
		exit(1);
	}

	fileinfo->fileCount = 0; // set file count = 0;
	int mode = 0;
	for (int i = 2; i < argc; i++) {
		int len = strlen(argv[i]);
		if (strcmp(argv[i] + len - 4, ".txt") == 0 || strcmp(argv[i] + len - 4, ".csv") == 0) {

			strcpy(fileinfo->files[fileinfo->fileCount].validFiles, argv[i]); 
			//printf("\n%s\n", fileinfo->files[fileinfo->fileCount].validFiles);
			fileinfo->files[fileinfo->fileCount].filesDescriptor = files_fd(fileinfo->files[fileinfo->fileCount].validFiles);

			fileinfo->fileCount++;
		} else {
			printf("\nskipping the \"%s\"\n", argv[i]);
		}
	}

	return fileinfo;
}

int files_fd(char* fileName) {
	int file_fd;
	file_fd = open(fileName, O_WRONLY | O_CREAT, 0666);
	if (file_fd == -1) {
		close(file_fd);
		perror("open");
		return errno;
	}
	return file_fd;
}


void* fileSeqGen(void* filedt){
	data* filedata = (data*)filedt;
	char buff[1024];
	int count = 0,mode = 0;
	int len = strlen(filedata->validFiles);
	if(strcmp(filedata->validFiles+len-4,".txt") == 0){
		mode = 1;
	}
	else{
		mode = 0;
	}
	for(int j=0; j<10000; j++){
		int r = rand();
		char num[20];
		if(count == 0 && mode == 1){

			sprintf(buff,"%d ",r);
			count++;
			continue;
		}
		else if(count == 0 && mode == 0){

			sprintf(buff,"%d,",r);
			count++;
			continue;
		}

		if(mode == 1){

			sprintf(num,"%d ",r);
		}
		else if(mode == 0){

			if(! (count >=9) ){
				sprintf(num,"%d,",r);
			}
			else{
				sprintf(num,"%d ",r);
			}
		}


		strcat(buff,num);
		count++;
		if(count == 10 && mode == 1){
			strcat(buff,"\n");
			//printf("%s",buff);
			write(filedata->filesDescriptor,buff,strlen(buff));
			count = 0;
			memset(buff,0,sizeof(buff));
		}
		else if(count == 10 && mode == 0){
			int blen = strlen(buff);
			strncat(buff,"\n",2);
			//printf("%s",buff);
			write(filedata->filesDescriptor,buff,strlen(buff));
			count = 0;
			memset(buff,0,sizeof(buff));
		}
	}

	close(filedata->filesDescriptor);
	pthread_exit(NULL);
}

void* wordCount(void* file){
    data* files = (data*)file;
    int count = 0,mode = 0,ret;
	int len = strlen(files->validFiles);
	if(strcmp(files->validFiles+len-4,".txt") == 0){
		mode = 1;
	}
	else{
		mode = 0;
	}

	long int fileSize;
	struct stat fileSpec;
	if(stat(files->validFiles,&fileSpec) == 0){
		fileSize = fileSpec.st_size;
	}
	char buff[fileSize];
	//printf("\nfileSize -> %ld\n",fileSize);
	//printf("\nfd %d\n",files.files[i].filesDescriptor);
	files->filesDescriptor  = open(files->validFiles,O_RDONLY,0666);
	if(files->filesDescriptor == -1){
		perror("open");
		fprintf(stderr,"%s",strerror(errno));
	}
	//printf("\nfd new -> %d\n",files.files[i].filesDescriptor);
	ret = read(files->filesDescriptor, buff, sizeof(buff));
	buff[ret] = '\0';
	//printf("\n%s\n",buff);
    char del[4];
    if(mode == 1){
        strcpy(del," \n");
    }
    else if(mode == 0){
        strcpy(del," ,\n");
    }
	char* token = strtok(buff,del);
	while(token != NULL){
		int len = strlen(token);
		// printf("\n len -> %d \nn  -> %d",len,n);
        pthread_mutex_lock(&own);
		if(len == n){
			sum++;
		}
        pthread_mutex_unlock(&own);
		token = strtok(NULL,del);
	}
	close(files->filesDescriptor);
}

