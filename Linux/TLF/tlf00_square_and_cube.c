#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

void *square(void* p) {
    int* n = (int*)p;
  int i;
  printf("\nsquare\n\n");
  for (i = 1; i <= *n; i++) {
    char temp[100];
    printf("square of %d = %d\n", i,(i*i));
    
  }
  pthread_exit(NULL);
   
}
void *cubes(void* p) {
  int i;
  int* n = (int*)p;
  printf("\nCubes\n\n");
  for (i = 1; i <= *n; i++) {
    int var = i*i*i;
    char temp[100];
    printf("cube of %d = %d\n", i,var);
    
  }
   pthread_exit(NULL);
}
int main() {

  printf("\n--TLF00 - Square and Cube--\n");
  int n =0,ret =0;
  write(1,"\nEnter the No : ",sizeof("\nEnter the No : "));
  scanf("%d",&n); 
  pthread_t pt1, pt2;

  ret = pthread_create(&pt1, NULL, square,&n);
  if(ret != 0){
    perror("pthread_create");
    return errno;
  }

  ret = pthread_create(&pt2, NULL, cubes,&n);
  if(ret != 0){
    perror("pthread_create");
    return errno;
  }
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  return 0; 
}