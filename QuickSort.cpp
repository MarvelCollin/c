#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return i + 1;
}

void quicksort(int arr[], int start, int end){
    if(start < end){
        int pivotIndex = partition(arr, start, end);

        quicksort(arr, start, pivotIndex - 1);

        quicksort(arr, pivotIndex + 1, end);
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    quicksort(array, 0, len - 1);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
