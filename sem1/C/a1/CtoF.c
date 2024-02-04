#include<stdio.h>
#include<stdlib.h>


void ctof();
void ftoc();


int main(){

	int ch; 

	while(1){
		printf("........................\n"
				"Enter your choice\n"
				"1. Centigrade to fahrenheit\n"
				"2. fahrenheit to Centigrade\n"
				"3. exit\n");
				
		fflush(stdin);
			
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				ctof();
				break;
				
			case 2:
				ftoc();
				break;
			case 3:
			
				exit(0);
		
		}	
	}

	return 0;
}


void ctof(){
	double c, f;
	printf("Enter the temperature value in centigrade\n");
	scanf("%lf", &c);
	
	f = (c*(9.0/5.0))+32.0;
	
	printf("converted temperature %lf\n ferenheight", f);
}


void ftoc(){
	double f, c;
	printf("Enter the temperature value in ferenheight\n");
	scanf("%lf", &f);
	
	c = (f-32.0)*(5.0/9.0);
	
	printf("converted temperature %lf\n centigrade", c);
}

