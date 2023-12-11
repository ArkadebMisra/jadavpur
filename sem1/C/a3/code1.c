#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student{
    char name[100];
    int roll;
    double marks[5];
    double average;
    double totMarks;
} STUDENT;


void insertionSort(STUDENT arr[], int n)
{
	int i, j;
    STUDENT key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j].totMarks < key.totMarks) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){
    int n;
    STUDENT s[100];
    int name[100];
    int temp;
    printf("reading the data from the file.\n");

    FILE *fp = fopen("student_data.csv","r");
    int i=0;
    while(!feof(fp)){
        fscanf(fp, "%[^,], %d, %lf, %lf, %lf, %lf, %lf\n", s[i].name, &s[i].roll, &s[i].marks[0], &s[i].marks[1],
                                     &s[i].marks[2], &s[i].marks[3], &s[i].marks[4]);

        s[i].totMarks = s[i].marks[0]+s[i].marks[1]+s[i].marks[2]+s[i].marks[3]+s[i].marks[4];
        s[i].average = s[i].totMarks/5;

        // printf("%s %d, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n",  s[i].name, s[i].roll, s[i].marks[0], s[i].marks[1],
        //                              s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].average, s[i].totMarks);
        i++;
    }
    insertionSort(s, i);
    for(int j=0;j<i;j++){
        printf("%s %lf\n", s[j].name, s[j].totMarks);
        // printf("\n");
    }

    fclose(fp);
    return 0;
}