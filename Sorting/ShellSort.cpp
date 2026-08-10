#include <stdio.h>

void shellsort(int arr[], int len){
    for(int gap = len / 2; gap > 0; gap /= 2){
        for(int i = gap; i < len; i++){
            int key = arr[i];
            int j = i;

            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    shellsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
