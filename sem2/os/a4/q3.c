// C program to illustrate 
// pipe system call in C 
// shared by Parent and Child 
#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <semaphore.h> 
#include<stdlib.h>
#include<string.h>
#define MSGSIZE 100 

int isPalindrome(char str[]) {
	printf("%s\n", str);
    int low = 0;
    int high = strlen(str) - 1;
 
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
	int p1[2], p2[2], pid, nbytes;    
 
	if (pipe(p1) < 0){
		exit(1);
	}

	if(pipe(p2) < 0){
		exit(1);
	} 
 
	if (fork() == 0) { 
		while(1){
			nbytes=0;

			while(nbytes==0){
				nbytes = read(p1[0], inbuf, MSGSIZE);
			}

			if(isPalindrome(inbuf)){
				write(p2[1], "yes", MSGSIZE);
			}
			else{
				write(p2[1], "no", MSGSIZE);
			}
		}
		printf("Finished reading\n"); 
		// Adding this line will 
		// not hang the program 
		close(p1[1]);
		close(p2[1]);  
	} 
 
	else { 
		while(1){
            char input[100], t;
			printf("Enter a string\n");
            gets(input);
			write(p1[1], input, MSGSIZE);


			nbytes=0;
			while(nbytes==0){
				nbytes = read(p2[0], inbuf, MSGSIZE);
			}

			if(!strcmp(inbuf, "yes")){
				printf("yes pallindrom\n\n");
			}
			else{
				printf("not pallindrom\n\n");
			}
		}
 
		close(p1[1]);
		close(p2[2]); 
 
	} 
	return 0; 
}