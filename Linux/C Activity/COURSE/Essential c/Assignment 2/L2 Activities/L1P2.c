#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct record{
    char* date[10];			
    char* Name[15];					
    int Age;					
    int Salary;					
    int EmployeeID;
}record;

void appendRecord(char* fileName){
    FILE* file = fopen(fileName,"a");
    if(file == NULL){
        printf("\n--- Error in opening File ---\n");
        return ;
    }
    record* rec = (record*)calloc(1,sizeof(record));
    if(rec == NULL){
        printf("\nMemory allocation failed\n");
        return ;
    }
    printf("\n--- Enter the below information to record the Employee details ---\n");
    printf("\nEnter the Date is this format \"dd/mm/yyyy\" : ");
    scanf("%s",rec->date);
    //printf("\n%s",rec->date);
    printf("\nEnter the Employee Name : ");
    scanf(" %[^\n]",rec->Name);
    //printf("\n%s",rec->date);
    printf("\nEnter the Employee Age : ");
    scanf("%d",&rec->Age);
    printf("\nEnter the Employee Salary : ");
    scanf("%d",&rec->Salary);
    printf("\nEnter the Employee ID : ");
    scanf("%d",&rec->EmployeeID);
    fprintf(file,"%s,%s,%d,%d,%d\n",rec->date,rec->Name,rec->Age,rec->Salary,rec->EmployeeID);
    free(rec);
    fclose(file);
}


void createRecord(char* fileName){
    FILE* file = fopen(fileName,"w");
    if(file == NULL){
        printf("\n--- File not created ---\n");
        return ;
    }
    fprintf(file,"Date,Name,Age,Salary,Employee ID\n");
    fclose(file);

}

void displayRecord(char* fileName){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("\n--- Error in opening File ---\n");
        return ;
    }
    char* buffer = (char*)calloc(300,sizeof(char));
    while(fgets(buffer,sizeof(buffer),file) != NULL){
        
        fputs(buffer,stdout);
        //printf("%s",buffer);
    }
    free(buffer);
    fclose(file);

}

void modifyRecord(char* fileName) {
    char Name[15];
    printf("\n\n-> Enter the Employee ID or Name to be modified in the record : ");
    scanf(" %[^\n]", Name);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\n--- Error in opening File ---\n");
        return;
    }
    strlwr(Name);

    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        printf("\n--- Error in opening temporary file ---\n");
        fclose(file);
        return;
    }

    char buffer[256];
    int flag = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char line[256];
        strcpy(line, buffer);
        strlwr(line);

        char* found = strstr(line, Name);
        if (found != NULL) {
            flag = 0;
            printf("\nFound the data for '%s': ", Name);
            printf("\n\nEnter the modified information of the Employee Named : \"%s\" ---\n\n",Name);
            record rec;
            printf("Enter the Date in this format \"dd/mm/yyyy\": ");
            scanf("%s", rec.date);
            printf("Enter the Employee Name: ");
            scanf(" %[^\n]", rec.Name);
            printf("Enter the Employee Age: ");
            scanf("%d", &rec.Age);
            printf("Enter the Employee Salary: ");
            scanf("%d", &rec.Salary);
            printf("Enter the Employee ID: ");
            scanf("%d", &rec.EmployeeID);
            fprintf(temp, "%s,%s,%d,%d,%d\n", rec.date, rec.Name, rec.Age, rec.Salary, rec.EmployeeID);
            continue;
        } else {
  
            fprintf(temp, "%s", buffer);
        }
    }

    fclose(temp);
    fclose(file);

    remove(fileName);
    rename("temp.csv", fileName);
    if (flag) {
    printf("\nRecord not found for the employee: %s\n", Name);
} else {
    printf("\nThe record named \"%s\" modified successfully\n", Name);
}
}


void deleteRecord(char* fileName) {
    char Name[15];
    printf("\n-> Enter the Employee ID or Name to delete the record : ");
    scanf(" %[^\n]", Name);
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\n--- Error in opening File ---\n");
        return;
    }
    strlwr(Name);

    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        printf("\n--- Error in opening temporary file ---\n");
        fclose(file);
        return;
    }

    char buffer[256];
    int flag = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char line[256];
        strcpy(line, buffer);
        strlwr(line);

        char* found = strstr(line, Name);
        if (found != NULL) {
            flag = 0;
            continue;
        } 
        else {
  
            fprintf(temp, "%s", buffer);
        }
    }

    fclose(temp);
    fclose(file);

    remove(fileName);
    rename("temp.csv", fileName);
    if (flag) {
        printf("\nRecord not found for the employee: %s\n", Name);
    } 
    else {
    printf("\nThe record named \"%s\" deleted successfully\n", Name);
    }
}

int main(){
    char filename[] = "record.csv";
    // createRecord(filename);
    // appendRecord(filename);
    // appendRecord(filename);
    displayRecord(filename);
    // appendRecord(filename);
    //modifyRecord(filename);
    deleteRecord(filename);
    displayRecord(filename);
    return 0;
}
