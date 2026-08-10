#include <stdio.h>

void bubblesort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    bubblesort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
