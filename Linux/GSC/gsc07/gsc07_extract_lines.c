#include <stdio.h> 		//For standard input / output
#include <stdlib.h> 	//For standard libararies for malloc, calloc, free
#include <errno.h>		//For syscall error calls
#include <fcntl.h>		//For flag macros
#include <unistd.h>		//for syscalls read, write, open
#include <string.h>	


int extractLines(int argc, char** argv);

int main(int argc, char** argv)
{
    if(argc < 3 || argc > 3)
	{
        errno=EINVAL;
            perror("Error");
		    return errno;
	}
    
	
    extractLines(argc,argv);

	return 0;
}

int extractLines(int argc, char** argv){

    int src_fd; 	
	src_fd = open(argv[2] , O_RDONLY);
    
	if(src_fd == -1)
	{
        printf("\n--%s\n",argv[3]);
		perror("open");
		close(src_fd);
		return errno;
	}
    int head = 0, tail = 0, count =0;

    if(sscanf(argv[1],"-%d,%d",&head,&tail) != 2){
        errno=EINVAL;
            perror("Error");
		    return errno;
    }
    //printf("\nh-> %d   t-> %d\n",head,tail);
    
    if(tail < 0 || head < 0){
        errno=EINVAL;
            perror("Error");
		    return errno;
    }
    
    char temp[tail][200];
    int cnt = tail-1,flag =0;
    int i=0,ret;
    char buff[1024],ch;
	while(ret = read(src_fd, &ch, 1))
	{
		if(ret == -1)
		{
			perror("read");
			return errno;
		}
        buff[i++] = ch;
        if(ch == '\n'){
            buff[i] = '\0';
            i = 0;
            if(tail >= head){
                if(count >= tail){
                        exit(0);
                    }
                if(count >= head){
                    printf("%s",buff);
                    
                }
                
            }
            else if(head >= tail){
                if(count >= head){
                        break;
                    }
                     if(count >= (head - tail)){
                    strcpy(temp[cnt--],buff);
                    
                }
            }
            count++;
        }
        
		
	}

    if(head > tail){
    for(int i=0; i<tail; i++){
        printf("%s",temp[i]);
    }
    }
	
    close(src_fd);

}

