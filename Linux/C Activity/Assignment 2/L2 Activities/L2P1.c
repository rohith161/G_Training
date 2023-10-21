
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    char date[11];
    char Name[16];
    int Age;
    int Salary;
    char EmployeeID[11];
} record;

void fileOperation();
int appendRecord(const char* fileName);
void createRecord(const char* fileName);
void deleteRecord(const char* fileName);
void modifyRecord(const char* fileName);
void displayRecord(const char* fileName);

int main() {
    fileOperation();
    return 0;
}

void fileOperation() {
    int e = 1;
    char fileName[21] = "";
    int mode;

    while (e == 1) {
        printf("\n--- File operation modes ---\n");
        printf("-> press \"0\" to create file\n");
        printf("-> press \"1\" to use an existing File\n");
        printf("-> press \"2\" to add information to the file\n");
        printf("-> press \"3\" to view records in the file\n");
        printf("-> press \"4\" to modify details in the file\n");
        printf("-> press \"5\" to delete a record in the file\n");
        printf("-> press \"6\" to exit\n -> input : ");
        scanf("%d", &mode);

        switch (mode) {
            case 0:
                printf("\nEnter the name of the file to be created with extension : ");
                getchar();
                scanf("%[^\n]", &fileName);
                createRecord(fileName);
                break;
            case 1:
                printf("\nEnter the name of the existing file with extension : ");
                getchar();
                scanf("%[^\n]", &fileName);
                FILE* file = fopen(fileName, "r");
                if (file == NULL) {
                    printf("\nFile not found --> \"%s\"", fileName);
                    fclose(file);
                    break;
                }
                printf("\nFile operation modes can be used for the file named \"%s\"", fileName);
                break;
            case 2:
                appendRecord(fileName);
                break;
            case 3:
                displayRecord(fileName);
                break;
            case 4:
                modifyRecord(fileName);
                break;
            case 5:
                deleteRecord(fileName);
                break;
            case 6:
                e = 0;
                break;
            default:
                break;
        }
    }
}

int appendRecord(const char* fileName) {
    if (strlen(fileName) <= 1) {
        printf("\n-- \"File name is missing\" --\n");
    }
    FILE* file = fopen(fileName, "a");
    if (file == NULL) {
        printf("\n--- Error in opening File \\ File not found ---\n");
        return 0;
    }
    record* rec = (record*)calloc(1, sizeof(record));
    if (rec == NULL) {
        printf("\nMemory allocation failed\n");
        return 0;
    }
    printf("\n--- Enter the below information to record the Employee details ---\n");
    printf("\nEnter the Date is this format \"dd/mm/yyyy\" : ");
    scanf("%s", rec->date);
    printf("\nEnter the Employee Name : ");
    scanf(" %[^\n]", rec->Name);
    printf("\nEnter the Employee Age : ");
    scanf("%d", &rec->Age);
    printf("\nEnter the Employee Salary : ");
    scanf("%d", &rec->Salary);
    printf("\nEnter the Employee ID : ");
    scanf("%s", rec->EmployeeID);
    fprintf(file, "%s,%s,%d,%d,%s\n", rec->date, rec->Name, rec->Age, rec->Salary, rec->EmployeeID);
    free(rec);
    fclose(file);
    printf("\nRecord added successfully\n");
    return 1;
}

void createRecord(const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\n--- File not created ---\n");
        return;
    }
    fprintf(file, "Date,Name,Age,Salary,Employee ID\n");
    printf("\n\"%s\" file created successfully\n", fileName);
    fclose(file);
}

void displayRecord(const char* fileName) {
    if (strlen(fileName) <= 1) {
        printf("\n-- \"File name is missing\" --\n");
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\n--- Error in opening File \\ File not found---\n");
        return;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        fputs(buffer, stdout);
    }
    fclose(file);
}

void modifyRecord(const char* fileName) {
    char EmpID[15];
    printf("\n\n-> Enter the Employee ID to modify data in the record : ");
    scanf(" %[^\n]", EmpID);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\n--- Error in opening File ---\n");
        return;
    }

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

        char* found = strstr(line, EmpID);
        if (found != NULL) {
            flag = 0;
            printf("\nFound the data for '%s': ", EmpID);
            printf("\n\nEnter the modified information of the Employee Named : \"%s\" ---\n\n", EmpID);
            record rec;
            printf("Enter the Date in this format \"dd/mm/yyyy\": ");
            scanf("%s", rec.date);
            printf("Enter the Employee Name: ");
            scanf(" %[^\n]", rec.Name);
            printf("Enter the Employee Age: ");
            scanf("%d", &rec.Age);
            printf("Enter the Employee Salary: ");
            scanf("%d", &rec.Salary);
            strcpy(rec.EmployeeID, EmpID);
            fprintf(temp, "%s,%s,%d,%d,%s\n", rec.date, rec.Name, rec.Age, rec.Salary, rec.EmployeeID);
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
        printf("\nRecord not found for the employee: %s\n", EmpID);
    } else {
        printf("\nThe record named \"%s\" modified successfully\n", EmpID);
    }
    exit(0);
}

void deleteRecord(const char* fileName) {
    if (strlen(fileName) <= 1) {
        printf("\n-- \"File name is missing\" --\n");
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\n--- Error in opening File \\ File not found ---\n");
        fclose(file);
        return;
    }
    char Name[15];
    printf("\n-> Enter the Employee ID to delete data in record : ");
    scanf(" %[^\n]", Name);

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

        char* found = strstr(line, Name);
        if (found != NULL) {
            flag = 0;
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
        printf("\nThe record named \"%s\" deleted successfully\n", Name);
    }
}


