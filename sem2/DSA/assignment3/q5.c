#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<malloc.h>


#define NO_STACKS 50


struct stack{
	int data;
	struct stack *next;
};

struct stack *top[NO_STACKS]; //= NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main(){
	int val, option;
    for(int i=0;i<NO_STACKS;i++){
        top[i] = NULL;
    }
    // struct stack *stacks[NO_STACKS];
    int no_stacks=0, stack_id;
	do{
		printf("\n *****MAIN MENU*****");
        printf("\n 1. CREATE A NEW STACK");
		printf("\n 2. PUSH");
		printf("\n 3. POP");
		printf("\n 4. PEEK");
		printf("\n 5. DISPLAY");
		printf("\n 6. EXIT");
		printf("\n Enter your option: ");
		scanf("%d",&option);
		switch(option){
            case 1:
                if(no_stacks==NO_STACKS){
                    printf("cant create any more stacks\n");
                }
                else{
                    no_stacks++;
                    printf("new stack created, identified by index %d\n", no_stacks-1);
                }
                break;
			case 2:
                printf("Enter the identifier of the stack\n");
                scanf("%d", &stack_id);

				printf("\n Enter the number to be pushed on stack: ");
				scanf("%d", &val);
				top[stack_id] = push(top[stack_id], val);
				break;
			case 3:
                printf("Enter the identifier of the stack\n");
                scanf("%d", &stack_id);

				top[stack_id] = pop(top[stack_id]);
				break;
			case 4:
                printf("Enter the identifier of the stack\n");
                scanf("%d", &stack_id);

				val = peek(top[stack_id]);
				if (val != -1)
				printf("\n The value at the top of stack is: %d", val);
				else
				printf("\n STACK IS EMPTY");
				break;
			case 5:

                printf("Enter the identifier of the stack\n");
                scanf("%d", &stack_id);

				top[stack_id] = display(top[stack_id]);
				break;
				
		}
	}while(option != 6);
	return 0;
}

struct stack *push(struct stack *top, int val){
	struct stack *ptr;
	ptr  = (struct stack*)malloc(sizeof(struct stack));
	ptr->data = val;
	if(top == NULL){
		ptr->next = NULL;
		top = ptr;
	}
	else{
		ptr->next = top;
		top = ptr;
	}
	return top;
}

struct stack *display(struct stack *top){
	struct stack *ptr;
	ptr = top;
	if(top == NULL){
		printf("Stack is empty\n");
	}
	else{
		while(ptr != NULL){
			printf("\n %d", ptr -> data);
			ptr = ptr -> next;
		}
	}
	return top;
}

struct stack *pop(struct stack *top){
	struct stack *ptr;
	ptr = top;
	if(top == NULL){
		printf("stack underflow\n");
	}
	else{
		top = top->next;
		printf("\n The value being deleted is: %d", ptr -> data);
		free(ptr);
	}
	return top;
}

int peek(struct stack *top){
	if(top==NULL)
		return -1;
	else
		return top ->data;
}