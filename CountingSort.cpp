#include <stdio.h>

void countingsort(int arr[], int len){
    int max = arr[0];

    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int count[max + 1];

    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }

    for(int i = 0; i < len; i++){
        count[arr[i]]++;
    }

    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }

    int temp[len];

    for(int i = len - 1; i >= 0; i--){
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    countingsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
