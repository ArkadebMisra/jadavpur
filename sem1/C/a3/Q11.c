#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Student {
    char name[30];
    int roll;
    int marks;
    char dob[30];
} STUDENT;

int main() {
    printf("Enter your choice:\n(1) Create the file\n(2) Add a new record\n(3) Delete a record specified by the roll number\n(4) Modify the marks of each student by adding grace marks\n");

    int choice;
    scanf("%d", &choice);
    FILE* fp;

    switch (choice) {
        case 1: {
            int input = 1, i = 0;
            STUDENT st[SIZE];
            fp = fopen("Dest.txt", "wb");
            if (!fp) {
                printf("Cannot open file");
                break;
            }
            while (input) {
                printf("Enter Details\n");
                printf("\tName: ");
                scanf("%*c");
                scanf("%[^\n]", st[i].name);
                printf("\tRoll: ");
                scanf("%d", &st[i].roll);
                printf("\tMarks: ");
                scanf("%d", &st[i].marks);
                printf("\tDate of Birth: ");
                scanf("%s", st[i].dob);
                fwrite(&st[i], sizeof(STUDENT), 1, fp);
                i++;
                printf("Do you want to insert another record? (1 for YES / 0 for NO): ");
                scanf("%d", &input);
            }
            fclose(fp);
            break;
        }

        case 2: {
            STUDENT st_new;
            fp = fopen("Dest.txt", "ab");
            if (!fp) {
                printf("Cannot open file");
                break;
            }
            printf("Enter Details\n");
            printf("\tName: ");
            scanf("%*c");
            scanf("%[^\n]", st_new.name);
            printf("\tRoll: ");
            scanf("%d", &st_new.roll);
            printf("\tMarks: ");
            scanf("%d", &st_new.marks);
            printf("\tDate of Birth: ");
            scanf("%s", st_new.dob);
            fwrite(&st_new, sizeof(STUDENT), 1, fp);
            fclose(fp);
            break;
        }

        case 3: 
        int rollToDelete;
        printf("Enter the roll number to delete: ");
        scanf("%d", &rollToDelete);

        FILE* tempFp = fopen("temp.txt", "wb"); // Create a temporary file

        fp = fopen("Dest.txt", "rb");
        if (!fp || !tempFp) {
            printf("Cannot open file");
            return 1;
        }

        STUDENT tempStudent;
        while (fread(&tempStudent, sizeof(STUDENT), 1, fp) == 1) {
            if (tempStudent.roll != rollToDelete) {
                fwrite(&tempStudent, sizeof(STUDENT), 1, tempFp); // Write all records except the one to delete to temp file
            }
        }

        fclose(fp);
        fclose(tempFp);

        remove("Dest.txt"); // Delete the original file
        rename("temp.txt", "Dest.txt"); // Rename the temp file to the original file name
        break;

        case 4: 
        int graceMarks = 10;
        

        fp = fopen("Dest.txt", "rb+");
        if (!fp) {
            printf("Cannot open file");
            return 1;
        }

        STUDENT tempStudent1;
        while (fread(&tempStudent1, sizeof(STUDENT), 1, fp) == 1) {
            // Modify marks by adding grace marks
            if(tempStudent1.marks >= 40 && tempStudent1.marks <= 50){
                tempStudent1.marks += graceMarks;
            }
            fseek(fp, -sizeof(STUDENT), SEEK_CUR); // Move the file pointer back to overwrite the record
            fwrite(&tempStudent1, sizeof(STUDENT), 1, fp); // Write the modified record
        }

        fclose(fp);
        break;
    }
    

    fp = fopen("Dest.txt", "rb");
    if (!fp) {
        printf("Cannot open file");
        return 1;
    }

    STUDENT temp;
    while (fread(&temp, sizeof(temp), 1, fp) == 1) {
        printf("%s %d\n", temp.name,temp.marks);
    }
    fclose(fp);

    return 0;
}
