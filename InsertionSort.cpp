#include <stdio.h>

void insertionsort(int arr[], int len){
    for(int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    insertionsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
