#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *start2=NULL;

struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the data\n");
	scanf("%d",&num);
	while(num!=-1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(start==NULL){
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr->next!=NULL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = NULL;
		}
		printf("Enter the data \n");
		scanf("%d",&num);
	}
	return start;
	
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL){
		printf("\t%d",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	return start;
}

int count(struct node *start){
    struct node *ptr = start;
    int c=0;
    while(ptr!=NULL){
        c++;
        ptr = ptr->next;        
    }
    return c;
}

struct node *reverse(struct node *start){
    struct node *ptr, *temp, *point_next=NULL;
    ptr=start;
    while(ptr->next!=NULL){
        // printf("%d ", ptr->data);
        temp = ptr->next;
        ptr->next = point_next;
        point_next=ptr;
        // printf("N%d ", point_next->data);
        ptr=temp;
    }
    ptr->next = point_next;
    start=ptr;
    // display(start);
    return start;
}

void find_index(struct node *start){
    printf("Entetr the value to find its index\n");
    int v;
    scanf("%d", &v);
    struct node *ptr = start;
    int found=0;
    printf("The indices are\n");
    int i=0;
    while(ptr!=NULL){
        if(ptr->data==v){
            printf("%d ", i);
            found = 1;
        }
        i++;
        ptr = ptr->next;
    }
    if(!found){
        printf("value not found\n");
    }
}

int indexed_element(struct node *start){
    struct node *ptr=start;
    int idx=0;
    printf("Enter a index i to find the element at index i\n");
    scanf("%d", &idx);
    int n = count(start);
    if(idx>n-1){
        printf("index out of bound\n");
        return -1;
    }
    int i=0;
    int e;
    while(ptr!=NULL){
        if(i==idx){
            e=ptr->data;
            break;
        }
        i++;
        ptr = ptr->next;
    }
    printf("The element at index %d is %d", idx, e);
    return e;

}
struct node *insert_begining(struct node *start, int val){
	struct node *ptr,*new_node;
	ptr = start;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = ptr;
	start = new_node;
	return start;	
}
struct node *insert_end(struct node *start, int val){
	struct node *ptr, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	new_node->next = NULL;
	ptr = start;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
	return start;
}

struct node *insert(struct node *start){
    int idx=0, val;
    int len = count(start);
    printf("Enter the value want to insert\n");
    scanf("%d", &val);
    printf("Enter index where you want to insert\n");
    scanf("%d", &idx);
    if(idx==0){
        start = insert_begining(start, val);
        return start;
    }
    if(idx==len){
        start=insert_end(start, val);
        return start;
    }

	struct node *new_node, *ptr, *pre_ptr;
	new_node = (struct node *)malloc(sizeof(struct node));
	ptr = start;
    int i=0;
	while(i<idx){
		pre_ptr = ptr;
		ptr = ptr->next;
        i++;
	}
	new_node->data = val;
	new_node->next = ptr;
	pre_ptr->next = new_node;
	return start;
	
}

struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr = start;
	start = start->next;
	free(ptr);
	return start;
}

struct node *delete(struct node *start){
    int idx=0;
    int len = count(start);
    printf("Enter index where you want to delete\n");
    scanf("%d", &idx);
    if(idx==0){
        start = delete_beg(start);
        return start;
    }

	struct node *ptr, *pre_ptr;
	ptr = start;
    pre_ptr=start;
    int i=0;
	while(i<idx){
		pre_ptr = ptr;
		ptr = ptr->next;
        i++;
	}
	pre_ptr->next = ptr->next;
	return start;
	
}

struct node *insert_after(struct node *start){
	struct node *new_node, *ptr, *post_ptr;
	int val, p_val;
	printf("Enter the data\n");
	scanf("%d",&val);
	printf("Enter the value after which the value has to be inserted\n");
	scanf("%d",&p_val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;
	ptr = start;
	while(ptr->data!=p_val){
		//printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	post_ptr = ptr->next;
	ptr->next = new_node;
	new_node->next = post_ptr;
	return start;
}

// struct node *delete_beg(struct node *start){
// 	struct node *ptr;
// 	ptr = start;
// 	start = start->next;
// 	free(ptr);
// 	return start;
// }

struct node *delete_end(struct node *start){
	struct node *ptr, *pre_ptr;
	ptr = start;
	while(ptr->next!=NULL){
		pre_ptr = ptr;
		ptr = ptr->next;
	}
	pre_ptr->next = NULL;
	free(ptr);
	return start;
}


struct node *delete_node(struct node *start){
	struct node *ptr, *pre_ptr, *post_ptr;
	int val;
	printf("Enter the data to be deleted\n");
	scanf("%d",&val);
	ptr = start;
	if(ptr->data==val){
		start = delete_beg(start);
		return start;
	}
	else{
		while(ptr->data!=val){
			pre_ptr = ptr;
			ptr = ptr->next;
		}
		post_ptr = ptr->next;
		pre_ptr->next = post_ptr;
		free(ptr);
		return start;	
	}

}

struct node *delete_after(struct node *start){
	int val;
	struct node *ptr,*post_ptr;
	printf("Enter the value after which the node has to be deleted\n");
	scanf("%d",&val);
	ptr = start;
	while(ptr->data!=val){
		ptr = ptr->next;
	}
	post_ptr = ptr->next;
	ptr->next = post_ptr->next;
	free(post_ptr);
	return start;
}

struct node *delete_list(struct node *start){
	struct node *ptr;
	if(start != NULL){
		ptr = start;
		while(ptr!=NULL){
			printf("%d is to be deleted next\n",ptr->data);
			start = delete_beg(ptr);
			ptr = start;			
		}
	}
	return start;
}

struct node *bubble_sort(struct node *start) {
    struct node *ptr1, *ptr2;
    int temp;
    if (start == NULL) // Check if the list is empty
        return start;
    
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                // Swap data
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    return start;
}


struct node  *merge_lists(struct node *start1, struct node *start2) {
    struct node *ptr;
    
    if (start1 == NULL) {
        start1 = start2;
        return start1;
    }

    ptr = start1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = start2;
    return start1;
}

void split_list(struct node *start) {
    int index;
    printf("Enter the index where you want to split\n");
    scanf("%d", &index);
    struct node *ptr = start, *prev = NULL;

    if (start == NULL || index < 0) {
        printf("Invalid index or empty list\n");
        return;
    }

    // Traverse to the specified index
    int count = 0;
    while (ptr != NULL && count < index) {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    // If index is out of bounds or at the beginning
    if (ptr == NULL || count == 0) {
        printf("Invalid index\n");
        return;
    }

    // Detach the second part from the original list
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        start = NULL; // If index is 0, start becomes NULL
    }

    start2 = ptr; // Assign the second part to start2
    printf("List splitted\n");
}


int main(){
	int option;
	do{
		printf("\n\n********MAIN MENU********");
		printf("\n 1.  Create a list");
		printf("\n 2.  Display the list");
		printf("\n 3.  count the number of elements in the array");
		printf("\n 4.  reverse the list");
		printf("\n 5.  find index of a given element");
		printf("\n 6.  Indexed element");
		printf("\n 7.  insert");
		printf("\n 8.  Delete");
		printf("\n 9.  merge");
		printf("\n 10. split");
		printf("\n 11.  sort");
		printf("\n 12. Exit");
		printf("\n\nEnter your option ");
		scanf("%d",&option);
		switch(option){
			case 1:
                printf("creating list one\n");
				start = create_ll(start);
				printf("\nLinked List created\n");
                printf("creating list 2\n");
                start2 = create_ll(start2);
                printf("\nLinked List2 created\n");
				break;
			case 2:
                printf("list 1: \n");
				start = display(start);
                printf("list 2: \n");
				start2 = display(start2);
				break;
			case 3:
				printf("There are %d elements in the array\n", count(start));
				// printf("Added\n");
				break;
			case 4:
				start = reverse(start);
				printf("reversed\n");
				break;
			case 5:
                find_index(start);
				break;
			case 6:
				indexed_element(start);
				// printf("Added\n");
				break;
			case 7:
				start = insert(start);
				printf("inserted\n");
				break;
			case 8:
				start = delete(start);
				printf("Deleted\n");
				break;
			case 9:
				start = merge_lists(start, start2);
				printf("Merged\n");
				break;
			case 10:
				split_list(start);
				printf("list splitted\n");
				break;
			case 11:
				start = bubble_sort(start);
				printf("list sorted\n");
				break;
			case 12:
				start = reverse(start);
				printf("reversed\n");
				break;
		}
	}while(option!=13);
	return 0;
}