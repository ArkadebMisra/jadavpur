// C program to illustrate 
// pipe system call in C 
// shared by Parent and Child 
#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <semaphore.h> 
#include<stdlib.h>
#define MSGSIZE 100 
 
sem_t s; 
sem_t q; 
int isPalindrome(char str[]) {
    int low = 0;
    int high = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (low < high) {
        if (str[low] != str[high]) {
            return 0; // not a palindrome.
        }
        low++; // move the low index forward
        high--; // move the high index backwards
    }
    return 1; // is a palindrome
}
 
 
int main() 
{ 
	char inbuf[MSGSIZE]; 
	int p[2], pid, nbytes; 
	sem_init(&s, 1, 0);
	sem_init(&q, 1, 0);
    int v;
    sem_getvalue(&s, &v);
    printf("%d", v);     
 
	if (pipe(p) < 0) 
		exit(1); 
 
	/* continued */
	if (fork() == 0) { 
		while(1){
			printf("child");
			sem_wait(&q);
			//printf("child");
			// nbytes = read(p[0], inbuf, MSGSIZE);
			printf("%s", inbuf);
			// if(nbytes==0){
			// 	continue;
			// }
			// else{
			// 	if(isPalindrome(inbuf)){
			// 		write(p[1], "yes", MSGSIZE);
			// 	}
			// 	else{
			// 		write(p[1], "no", MSGSIZE);
			// 	}
			// }
			// sem_post(&s);
		}
		printf("Finished reading\n"); 
		// Adding this line will 
		// not hang the program 
		// close(p[1]);  
	} 
 
	else { 
        	// 		printf("Enter a string\n");
			// scanf("%c", &t);
            // printf("%c", t);
		while(1){
            char input[100], t;
            // fflush(stdin);
            // while ((getchar()) != '\n');
			printf("Enter a string\n");
			// scanf("%[^\n]s", input);
            gets(input);
            // t = getchar();
            printf("%s\n", input);
			// write(p[1], input, MSGSIZE);

			sem_post(&q);
            
            sem_getvalue(&q, &v);
            printf("%d",v);

			// sem_wait(&s);
			// nbytes = read(p[0], inbuf, MSGSIZE);
			// if(strcmp(inbuf, "yes")){
			// 	printf("yes pallindrom");
			// }
			// else{
			// 	printf("not pallindrom");
			// }
		}
 
		// Adding this line will 
		// not hang the program 
		close(p[1]); 
 
	} 
	return 0; 
}