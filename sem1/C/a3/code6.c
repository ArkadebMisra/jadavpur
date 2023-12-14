#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct book{
    int accessionNo;
    char title[100];
    char author[100];
    double price;
    int isIssued;
} BOOK;


void insertionSort(BOOK arr[], int n)
{
	int i, j;
    BOOK key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j].accessionNo > key.accessionNo) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){
    int n;
    BOOK books[1000];
    char temp[100];
    int temp1;
    // char author[100];
    printf("reading the data from the file.\n");

    FILE *fp;
    int i=0;

    int choice;
    int exit = 0;

    while(!exit){
        printf("===================================\n"
                "Enter your choice\n"
                "1. add book information\n"
                "2. Display book information\n"
                "3. List all books of given author\n"
                "4. List the title of specified book\n"
                "5. List the count of books in the Library\n"
                "6. List the books in order of accession NO\n"
                "7. Exit\n\n");

        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            // char filename[100];
            printf("Enter the file name of library information\n");
            char ch;
            scanf("%s%c", temp,&ch);
            fflush(stdin);

            fp = fopen(temp,"r");

            // printf("here\n");
            
            while(!feof(fp)){
                fscanf(fp, "%d, %[^,], %[^,], %lf, %d\n", &books[i].accessionNo,books[i].title, books[i].author, &books[i].price, &books[i].isIssued);
                // fflush(stdin);
                i++;
            }
            // insertionSort(books, i);
            // for(int j=0;j<i;j++){
            //     printf("%s %lf\n", books[j].title, books[j].price);
            //     // printf("\n");
            // }
            fflush(stdin);
            fclose(fp);

            break;
        case 2:
            printf("Enter the accession NO to print info of the book\n");
            
            // scanf("%*c");
            scanf("%d", &temp1);
            printf("%d", temp1);
            fflush(stdin);
            int c = 0;
            printf("\n");
            for(int j=0;j<i;j++){
                printf("%d\n", books[j].accessionNo);
                if(temp1 == books[j].accessionNo){
                    
                    printf("%d, %s, %s, %.2lf, %s\n", books[j].accessionNo, books[j].title,books[j].author,  books[j].price, books[j].isIssued?"issued":"not issued");
                    c++;
                    break;
                }
                printf("\n");
                
            }
            if(c==0){
                printf("No books found\n");
            }
            break;
        case 3:
            // fflush(stdin);
            printf("Enter the author name to search\n");
            
            scanf("%*c");
            scanf("%[^\n]", temp);
            // printf("%s", temp);
            fflush(stdin);
            c = 0;
            printf("\n");
            for(int j=0;j<i;j++){
                if(strcmp(temp, books[j].author)==0){
                    printf("%s, ",books[j].title);
                    printf("\n");
                }
                c++;
            }
            if(c==0){
                printf("No books found\n");
            }
            break;

        case 4:
            // fflush(stdin);
            printf("Enter the accession NO to print the title\n");
            
            // scanf("%*c");
            scanf("%d", &temp1);
            // printf("%s", temp);
            fflush(stdin);
            c = 0;
            printf("\n");
            for(int j=0;j<i;j++){
                if(temp1 == books[j].accessionNo){
                    printf("%s, ",books[j].title);
                    printf("\n");
                    c++;
                    break;
                }
                // printf("\n");
                
            }
            if(c==0){
                printf("No books found\n");
            }
            break;
        
        case 5:
            printf("There are %d books in the library\n",i);
            break;

        case 6:
            insertionSort(books, i);
            printf("sorted books\n");
            for(int j=0;j<i;j++){
                printf("%d, %s, %s, %.2lf, %s\n", books[j].accessionNo, books[j].title,books[j].author,  books[j].price, books[j].isIssued?"issued":"not issued");
                // printf("\n");
            }
            break;
        case 7:
            exit = 1;
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }

    }



    return 0;
}