#include <stdio.h>
int dequeue(int arr[], int *size){
	(*size)--;

	return arr[*size];
}

void enqueue(int val, int arr[], int *size, int capacity){
	if (capacity == *size){
		return;
	}

	//Shift all elements to the right.
	for (int i = *size - 1; i >= 0; i--){
		arr[i+1] = arr[i];
	}

	arr[0] = val;
	(*size)++;
}

// void print_queue(int arr[], int *size){ use this if use pointer for size
void print_queue(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
		//We add and shift one value to the right, so printf will print the newset value to oldest value.
	}
}

int main(){
	int arr[5] = {0};
	int size = 0;

	enqueue(1,arr,&size,5);
	enqueue(3,arr,&size,5);
	enqueue(7,arr,&size,5);
	enqueue(9,arr,&size,5);
	enqueue(11,arr,&size,5);
	enqueue(13,arr,&size,5); //for checking the capacity

	print_queue(arr, size);
	// print_queue(arr, &size); same as above

	int val = dequeue(arr, &size);

	printf("dequeue item is %d\n", val);
	print_queue(arr, size);
	// print_queue(arr, &size);
	return 0;
}