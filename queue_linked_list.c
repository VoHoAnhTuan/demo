// Enqueue at the head of the list
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node *next;
	Node *prev;
};

int dequeue(Node **last) {
	if ((*last)->prev == NULL){

	}

	Node *prev = (*last)->prev;
	prev->next = NULL; 
	
	int return_val = (*last)->data;
	free(*last);
	*last = prev;

	prev->next = NULL;

	return return_val;
}

//If we use Node *head only, we will lose the address of head when we go to main.
Node *enqueue(int data, Node **head) {
	Node *new_node = calloc(1, sizeof(Node));
	Node *last = NULL;
	new_node->data = data;
	//new_node becomes the head of the list
	new_node->next = *head;

	//The now second item should point back to the new head
	if (*head != NULL){
		(*head)->prev = new_node;
		last = *head;
	} else{
		last = new_node;
	}

	//Update the head of the list so it can be seen in main
	*head = new_node;

	return last;
}

void print_queue(Node *head){
	while( head != NULL){
		printf("data = %d\n", head->data);
		head = head->next;
	}
}

int main() {
	Node *head = NULL;
	Node *last = NULL;

	last = enqueue(5,&head);
	last = enqueue(11,&head);

	printf("last: %p\n", last);
	printf("head->next: %p\n", head->next);


	print_queue(head);

	
	return 0;
}