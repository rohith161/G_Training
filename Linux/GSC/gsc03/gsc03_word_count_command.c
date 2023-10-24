#include <stdio.h> 		//For standard input / output
#include <errno.h>		//For syscall error calls
#include <fcntl.h>		//For flag macros
#include <unistd.h>		//for syscalls read, write, open

int wordCount(int argc, char** argv);

int main(int argc, char** argv){
	
	if(argc < 2){
		fprintf(stderr,"\n%s:missing input file\n",argv[0]);
		return EINVAL;	

	}
	else if(argc > 2){
		errno=EINVAL;
            perror("Error");
		    return errno;
	}

	wordCount(argc,argv);
	return 0;
}


int wordCount(int argc, char** argv){

	
	int src_fd;
	int lineCount = 0, wordCount = 0, charCount = 0;
	int status;
	char ch;
	src_fd = open(argv[1], O_RDONLY);
	if(src_fd == -1){
		perror("open");
		return errno;
	}
	char prev ;
	while(status = read(src_fd,&ch,1)){
		if(status == -1){
			perror("read");
			return errno;
		}
		
		  if (ch != '\0') {
            charCount++;
        }

        if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\v') && prev != ' ' && prev != '\n' && prev != '\t' && prev != '\r' && prev != '\v') {
            wordCount++;
        }

        if (ch == '\n') {
            lineCount++;
        }
        prev = ch;
    }

    
	printf(" %d %d %d %s\n",lineCount,wordCount,charCount,argv[1]);
	close(src_fd);

}