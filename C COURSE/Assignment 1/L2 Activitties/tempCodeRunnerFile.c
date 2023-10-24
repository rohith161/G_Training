void appendFile(char* name){
    FILE* file = fopen(name,"a");
    if(file == NULL){
        printf("\nFILE NOT FOUND\n");
        return ;
    }
    char *h = readFile(name);
    //printf("%s\n",h);
    char buf[1024] = "";
    char* Token = strtok(h,",");
        while (Token != NULL)
        {
            printf("%s ->",Token);
            char temp[50];
            Token = strtok(NULL,",");
            fgets(temp,sizeof(temp),stdin);
            strtok(temp,"\n");
            strcat(buf,temp);
            //strncpy(buf+strlen(buf),temp,strlen(temp)-1);
            //strcat(buf-1,temp);
            if(strlen(temp) > 0){
                //strcat(buf-2,",");
                strcat(temp,",");
            }
            // else{
            //     strcat(temp,"\n");
            // }
        }
        strcat(temp,"\n");
        fputs(buf,file);
        //printf("\n");
    // for(int i=0; i<20; i++){
    //     printf("%s -> ",h[i]);
    //     char buffer[100];
    //     fgets(buffer,sizeof(buffer),stdin);
    //     fputs(buffer,file);
    //     printf("\n");
    // }

        fclose(file);
}