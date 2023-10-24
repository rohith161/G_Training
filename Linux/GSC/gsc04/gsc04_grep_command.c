#include <stdio.h> 		//For standard input / output
#include <stdlib.h> 	//For standard libararies for malloc, calloc, free
#include <errno.h>		//For syscall error calls
#include <fcntl.h>		//For flag macros
#include <unistd.h>		//for syscalls read, write, open
#include <string.h>		


int grep(int argc, char** argv);
void subSequence(char* buff,int argc,char** argv);
void countSequence(char* buff,int argc,char** argv,int* count);
void lowerCase(char* str);

int main(int argc, char** argv)
{
    if( argc < 3  || argc > 4){
        errno=EINVAL;
            perror("Error");
		    return errno;
    }
    grep(argc,argv);

	return 0;
}

int grep(int argc, char** argv){
    
	int src_fd; 	// fd for source files
	int retnum; 	 	// To store the return value of the functions
	char ch;		// character variable
    if(argc == 3){
	    src_fd = open(argv[2] , O_RDONLY);
    }
    else if( argc == 4){
        src_fd = open(argv[3] , O_RDONLY);
        
    }
    
	if(src_fd == -1)
	{
        printf("\n--%s\n",argv[3]);
		perror("open");
		close(src_fd);
		return errno;
	}

    int count =0;
    int i=0;
    char buff[1024];
	while(retnum = read(src_fd, &ch, 1))
	{

		if(retnum == -1)
		{
			perror("read");
			return errno;
		}

        if(strcmp(argv[1],"-i") == 0 || strcmp(argv[1],"-ci") == 0 || strcmp(argv[1],"-ic") == 0){
            if(ch >= 'A' && ch <= 'Z'){
            ch += 32;
        }
        }

        buff[i++] = ch;
        if(ch == '\n'){
            buff[i] = '\0';
            i = 0;
            if(argc == 3 || strcmp(argv[1],"-i") == 0){
                
                subSequence(buff,argc,argv);
            }
            else if(argc == 4){
                countSequence(buff,argc,argv,&count);
            }
            continue;
        }
		
	}
    if(argc == 4 && (strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"-ci") == 0 || strcmp(argv[1],"-ic") == 0)){
        printf("%d\n",count);
    }
	
    close(src_fd);

}

void subSequence(char* buff,int argc,char** argv){
    char red_start[] = "\033[0;31m";
    char red_end[] = "\x1b[0m";
    int blen = strlen(buff), rs = strlen(red_start), rd = strlen(red_end);

    if (argc == 3) {
        char *sub = strstr(buff, argv[1]);

        if (sub != NULL) {
            int pos = sub - buff;
            int plen = strlen(argv[1]);
            char temp[blen+rs+rd]; // to accomadte the string coloring format
            strncpy(temp,buff,pos);
            temp[pos] = '\0';
            strncat(temp,red_start,rs);
            strncat(temp,buff+pos,plen);
            strncat(temp,red_end,rd);
            strncat(temp,buff+pos+plen,blen-pos-plen);
            printf("%s",temp);
        }
    }
    else if(argc == 4 && strcmp(argv[1],"-i") == 0){
            //printf("\nyes\n");
            char temp[strlen(buff)+rs+rd];
            int plen = strlen(argv[2]) ;   
            lowerCase(argv[2]);
            char *sub = strstr(buff, argv[2]);
            if (sub != NULL) {
                int pos = sub - buff;
                char temp[blen+rs+rd]; // to accomadte the string coloring format
                strncpy(temp,buff,pos);
                temp[pos] = '\0';
                strncat(temp,red_start,rs);
                strncat(temp,buff+pos,plen);
                strncat(temp,red_end,rd);
                strncat(temp,buff+pos+plen,blen-pos-plen);
                printf("%s",temp);
            }
        }
        memset(buff, 0, sizeof(buff)); // Clear the buffer
    
  
    return ;
}

void countSequence(char* buff,int argc,char** argv,int* count){

        if (strcmp(argv[1],"-c") == 0)
        {
            
            char *sub = strstr(buff, argv[2]);
            if(sub != NULL){
                (*count)++;
                return;
            }
        }
        else if(strcmp(argv[1],"-ci") == 0 || strcmp(argv[1],"-ic") == 0){
            
            lowerCase(argv[2]);
            char* ret = strstr(buff,argv[2]);
            if(ret != NULL){
                (*count)++;
                return;
            }
        }
        

}

void lowerCase(char* str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }

}
