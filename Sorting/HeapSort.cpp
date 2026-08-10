#include <stdio.h>

void heapify(int arr[], int len, int index){
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < len && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < len && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        heapify(arr, len, largest);
    }
}

void heapsort(int arr[], int len){
    for(int i = len / 2 - 1; i >= 0; i--){
        heapify(arr, len, i);
    }

    for(int i = len - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    heapsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
