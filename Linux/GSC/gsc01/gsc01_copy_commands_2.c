#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	int src_fd, dest_fd; 	// fd for source and destination files
	int status; 	 	// To store the return value of the functions
	char buff[1024];		// character variable

	if(argc == 1)		// if the arguments doesn't contain the source and destination target names
	{
		fprintf(stderr,"\n\'%s\' -> not mentioned the \'source\' and \'destination\' target\n",argv[0]);
		return EINVAL;
	}
	
	else if(argc == 2)	// To check if the destination target has mentioned 
	{
		fprintf(stderr,"\n\'%s\' source -> missing \'destination\' target\n",argv[1]);
		return EINVAL;
	}
	

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


	while(status = read(src_fd, buff, 1024))
	{

		if(status == -1)
		{
			perror("read");
			return errno;
		}

		status = write(dest_fd, buff, 1024);
		if(status == -1)
		{	
			perror("write");
			return errno;
		}
		
	}
		printf("\nCopied the contents of \'%s\' chunk by chunk to \'%s\' successfully \n\n",argv[1],argv[2]);
		close(src_fd);
		close(dest_fd);


}
