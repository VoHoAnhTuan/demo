#include <stdio.h>
#include <stdlib.h>

int dequeue(int **arr, int *size){
	(*size)--;

	int return_val = (*arr)[*size];

	*arr = realloc(*arr, sizeof(int) * (*size));

	return return_val;
}

//using double pointer because arr get a new address adter we realloc, if not ** we lose that adress when we go back main.
void enqueue(int val, int **arr, int *size){ 
	*arr = realloc(*arr, sizeof(int) * (*size + 1));

	//Shift all elements to the right.
	for (int i = *size - 1; i >= 0; i--){
		// *arr[i+1] = *arr[i]; this line of code will create seg fault, so see the line below
		(*arr)[i+1] = (*arr)[i]; // Without the parenthesis it means it grabs the element as [i+1] which is ** NOT the value,and deference it.
		//(*arr) means we deference to get the address from ** and THEN we get the actual values by the Index.
	}

	(*arr)[0] = val; //change *arr[0] to (*arr)[0] as well
	(*size)++;
}

// void print_queue(int arr[], int *size){ use this if use pointer for size
void print_queue(int *arr, int size){
	for (int i = 0; i < size; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
		//We add and shift one value to the right, so printf will print the newset value to oldest value.
	}
}

int main(){
	int *arr = NULL;
	int size = 0;

	enqueue(1,&arr,&size);
	enqueue(3,&arr,&size);
	enqueue(7,&arr,&size);
	enqueue(9,&arr,&size);
	enqueue(11,&arr,&size);
	enqueue(13,&arr,&size); //for checking the capacity

	print_queue(arr, size);
	// print_queue(arr, &size); same as above

	int val = dequeue(&arr, &size);

	printf("dequeue item is %d\n", val);
	print_queue(arr, size);
	// print_queue(arr, &size);

	free(arr);
	return 0;
}