#include <stdio.h> 		//For standard input / output
#include <stdlib.h> 	//For standard libararies for malloc, calloc, free
#include <errno.h>		//For syscall error calls
#include <fcntl.h>		//For flag macros
#include <unistd.h>		//for syscalls read, write, open

int copyChunkByChunk(int argc, char** argv);

int main(int argc, char** argv)
{

	if(argc <= 1)		// if the arguments doesn't contain the source and destination target names
	{
		fprintf(stderr,"\'%s\' -> not mentioned the \'source\' and \'destination\' target\n",argv[0]);
		return EINVAL;
	}
	
	else if(argc > 3 || argc < 3)	// To check if the destination target has mentioned 
	{
		errno = EINVAL;
		perror("Error");
		return EINVAL;
	}

	copyChunkByChunk(argc,argv);
	
	return 0;
}


int copyChunkByChunk(int argc, char** argv){

	int src_fd, dest_fd; 	// fd for source and destination files
	int retnum; 	 	// To store the return value of the functions
	char buff[1024];		// character variable
	

	src_fd = open(argv[1] , O_RDONLY);
	if(src_fd == -1)
	{
		perror("open");
		close(src_fd);
		return errno;
	}
	
	dest_fd = open(argv[2] , O_WRONLY | O_CREAT , 0666);
	if(dest_fd == -1)
	{
		perror("open");
		close(dest_fd);
		return errno;
	}


	while(retnum = read(src_fd, buff, 100))
	{

		if(retnum == -1)
		{
			perror("read");
			return errno;
		}
	
		retnum = write(dest_fd, buff, retnum);
		
		if(retnum == -1)
		{	
			perror("write");
			return errno;
		}
		
	}
		printf("\nCopied the contents of \'%s\' chunk by chunk to \'%s\' successfully \n\n",argv[1],argv[2]);
		close(src_fd);
		close(dest_fd);

}