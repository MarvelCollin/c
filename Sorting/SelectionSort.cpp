#include <stdio.h>

void selectionsort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    selectionsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
