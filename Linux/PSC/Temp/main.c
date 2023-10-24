#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

int Q_No = 1;
int dest_fd; 

void alarm_handler(int signal);
int quiz();

int main() {
    
    quiz();
    return 0;
}

int quiz(){

    int src_fd = open("qb.txt", O_RDONLY);
    if (src_fd == -1) {
        close(src_fd);
        perror("open");
        return errno;
    }

    dest_fd = open("answer.csv", O_WRONLY | O_CREAT ,0666);
    if (dest_fd == -1) {
        close(dest_fd);
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    signal(SIGALRM, alarm_handler); // when the alarm which is set for 5 has completed
                                    // - it delevers the SIGALRM then we provide the time;s up message 
    char buff[1024];
    int i = 0,status;
    char ch;
    while (read(src_fd, &ch, 1) > 0) {
        buff[i++] = ch;
        
        if(ch == '\n' ){
            buff[i] = '\0';
            i = 0;
            char ans[50];
            
            int ret = fork();
            if(ret == -1){
                perror("fork");
                exit(0);
            }

            int readByte;
            if(ret == 0){

                alarm(5);
                printf("\nQ_No %d : %s", Q_No,buff);
                fprintf(stderr,"Enter your answer: ");
                readByte = read(0,ans, sizeof(ans));
                ans[readByte] = '\0';
                alarm(0);                   // reset the alarm;
                if (readByte > 1) {
                    char temp[100];
                    sprintf(temp, "%d,%s",Q_No, ans);
                    write(dest_fd, temp, strlen(temp));
                    Q_No++;
                    
                }
                else if(readByte == 1 || ans[0] == '\n'){
                    char temp[100];
                    sprintf(temp, "%d,%s",Q_No, "NA\n");
                    write(dest_fd, temp, strlen(temp));
                    Q_No++;
                }
            }
            else{
                waitpid(ret,&status,0);
                printf("\nstatus -> %d\n",status);
                if(status == 0){
                char temp[100];
                sprintf(temp, "%d,%s\n",Q_No,"NA");
                write(dest_fd, temp, strlen(temp));
                Q_No++;
                }
            }
        }
    }
    close(dest_fd);
    close(src_fd);
}


void alarm_handler(int signal) {
    printf("\n\nTime is up! \n\n");
    exit(0);
}