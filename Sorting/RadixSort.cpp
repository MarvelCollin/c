#include <stdio.h>

void countingByDigit(int arr[], int len, int digit){
    int temp[len];
    int count[10];

    for(int i = 0; i < 10; i++){
        count[i] = 0;
    }

    for(int i = 0; i < len; i++){
        count[(arr[i] / digit) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(int i = len - 1; i >= 0; i--){
        int index = (arr[i] / digit) % 10;
        temp[count[index] - 1] = arr[i];
        count[index]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = temp[i];
    }
}

void radixsort(int arr[], int len){
    int max = arr[0];

    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    for(int digit = 1; max / digit > 0; digit *= 10){
        countingByDigit(arr, len, digit);
    }
}

int main(){
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int len = sizeof(array) / sizeof(array[0]);

    radixsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
