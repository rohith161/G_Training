/*Write a C program which inputs a file as a command-line arguments and detects whether the file is JPEG or not.	
Approach:										
1. We will give an image as a command line argument while executing the code.				
2. Read the first three bytes of the given image(file).							
3. After reading the file bytes, compare it with the condition for JPEG file i.e., if the first, second, and third byte of the given file is 0xff, 0xd8, and 0xff respectively then the given file is JPEG file.
4. Else it is not a JPEG File.*/

#include <stdio.h>
#include <string.h>


int readFormat(char* s);

int main(int argc,char **argv){
    //printf("\n%d\n%s\n",argc,argv[1]);
    readFormat(argv[1]);
    return 0;
}

int readFormat(char* str){
    printf("\n->%s\n",str);
    int len = strlen(str);
    char s[len];
    strcpy(s,str);
    //printf("\n---->%s\n",s);
    if(strlen(s) == 4){
        printf("\nUnable to recognize the file format\n");
        return 0;
    }
    while (1)
    {
        char* pos = strstr(s,".jpg");
        if(pos == NULL){
            printf("\nUnable to recognize the file format\n");
            return 0;
        }
        else if(strlen(pos) == 4){
            printf("\nAble to recognize the file format\n");
            return 1;
        }
        else if(strlen(pos) > 4){
            //pos = pos[4];
            strncpy(pos,pos+4,strlen(pos)-4);
            continue;
        }
        
    }
    
}
