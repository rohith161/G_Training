#define _GNU_SOURCE

#include<stdio.h>

#include<string.h>

#include<unistd.h>

#include<stdlib.h>

 

void err_handling(int);

int validate_file_name(const char *);

 

int main(int argc, char *argv[]){

    int err_code=0;

   

    if(argc < 2){

        err_code=1;

        err_handling(err_code);

    }

   

    else if(argc > 2){

        err_code=2;

        err_handling(err_code);

   

    }

   

    int check_ip = validate_file_name(argv[1]);

    if(check_ip == 1){

        err_code=3;

        err_handling(err_code);

   

    }

 

    else if(check_ip == 2){

        err_code=4;

        err_handling(err_code);

   

    }

 

    FILE *fp=fopen(argv[1],"rb");

 

    if (fp == NULL)

    {

        printf("File doesnt exist\n");

    }

 

    unsigned char temp[4];

    size_t numb_char_read = fread(temp,sizeof(temp),1,fp);

    // printf("\n\n%ld\n\n",numb_char_read);

    // printf("%x %x %x\n\n",temp[0],temp[1],temp[2]);

    if(temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff){

        err_code = 5;

        err_handling(err_code);

       

    }

    else{

        err_code = 6;

        err_handling(err_code);

        }

    // printf("\n\n\t\t%ld",sizeof(temp));

    fflush(fp);

    fclose(fp);

    return 0;

}

 

int validate_file_name(const char *haystack){

#if 0      

    printf("%s\n", haystack);

    haystack[0] = 'J';

    printf("%s\n", haystack);

#endif

 

    if(haystack[0]=='.'){

        return 3;

    }

    char needle[]=".jpg";

    char *chr = strstr(haystack,needle);

    if(chr==NULL){

        return 3;

    }

    else if(strlen(chr)!=4){

        return 3;

    }

    else{

        return 4;

    }

 

}

 

void err_handling(int err_code){

    switch(err_code){

        case 1:{

            printf("Too few arguments. Aborting\n");

            exit(0);

        }

        case 2:{

            printf("Too many arguments. Aborting\n");

            exit(0);

        }

        case 3:{

            printf("File name doesnot match required parameters\n");

            printf("Proceeding to check file signature\n");

            break;

        }

        case 4:{

            printf("File name matches required parameters\n");

            printf("Proceeding to check file signature\n");

            break;

        }

        case 5:{

            printf("File signature matches that to a JPEG/JPG file\n");

            printf("Success\n");

            exit(0);

        }

        case 6:{

            printf("File signature doesnot match that to a JPEG/JPG file\n");

            printf("Aborting\n");

            exit(0);

        }

        default:

            printf("This should never execute\n");

    }

}