#include<stdio.h>

#define NO_STACKS 50
#define STACK_CAPACITY 100

struct StackObject{
    int stack[STACK_CAPACITY];
    int top;
};

void push(struct StackObject *stack, int data){
    if(stack->top==STACK_CAPACITY-1){
        printf("cant push to stack, stack overflow\n");
    }
    else{
        stack->top++;
        stack->stack[stack->top] = data;
    }
}

void print_stack(struct StackObject *stack){
    for(int i=0;i<=stack->top;i++){
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

int peek(struct StackObject *stack){
    if(stack->top<0){
        printf("underflow\n");
        return -1;
    }
    else{
        return stack->stack[stack->top];
    }
}

int pop(struct StackObject *stack){
    if(stack->top<0){
        printf("underflow\n");
        return -1;
    }
    else{
        int t = stack->top;
        stack->top--;
        return stack->stack[t];

    }
}

int main(){
    struct StackObject *stacks[NO_STACKS];
    int no_stacks=0;
    int ch, stack_id, data;
    int run=1;
    while(run){
        printf("\n\n");
        printf("choose an option\n");
        printf("1. create a stack\n");
        printf("2. push on the stack\n");
        printf("3. peek the stack\n");
        printf("4. pop from the stack\n");
        printf("5. print the stack\n");
        printf("6. exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if(no_stacks==NO_STACKS){
                printf("cant create any more stacks\n");
            }
            else{
                no_stacks++;
                struct StackObject new_stack;
                new_stack.top = -1;
                stacks[no_stacks-1] = &new_stack;
                printf("new stack created, identified by index %d\n", no_stacks-1);
            }
            break;
        case 2:
            printf("Enter the identifier of the stack\n");
            scanf("%d", &stack_id);
            printf("Enter data to push on the stack\n");
            scanf("%d", &data);
            push(stacks[stack_id], data);
            break;

        case 3:
            printf("Enter the identifier of the stack\n");
            scanf("%d", &stack_id);
            printf("peeked data %d from stack identified by %d\n", peek(stacks[stack_id]), stack_id);
            break;

        case 4:
            printf("Enter the identifier of the stack\n");
            scanf("%d", &stack_id);
            printf("popped %d from stack identified by %d\n", pop(stacks[stack_id]), stack_id);
            break;

        case 5:
            printf("Enter the identifier of the stack\n");
            scanf("%d", &stack_id);
            print_stack(stacks[stack_id]);
            break;
        case 6:
            run=0;
            break;

        
        default:
            printf("invalid option\n");
            break;
        }

        
    }

    return 0;
}