#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define TIMEOUT 5
int i=0;
void *timer(void *t,char* Q,char* answer) {
    i=0;
    for (i = 1; i <= TIMEOUT; i++) {
        printf("%s\tTimer:[ %d ]\n",Q,i); 
        fflush(stdout); 
        sleep(1); 
    }
    printf("\nTime's up!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    char answer[100];

    int n = 0;
    pthread_create(&tid, NULL, timer(&n,"Q: What is the capital of France?",answer), NULL);
    printf("\rYour answer: ");
    printf("\033[F"); 
        fgets(answer, sizeof(answer), stdin);
    pthread_cancel(tid);

    printf("Your answer was: %s\n", answer);

    return 0;
}
