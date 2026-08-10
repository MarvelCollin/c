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

void bucketsort(int arr[], int len){
    int max = arr[0];

    for(int i = 1; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int bucket[len][len];
    int bucketSize[len];

    for(int i = 0; i < len; i++){
        bucketSize[i] = 0;
    }

    for(int i = 0; i < len; i++){
        int index = arr[i] * len / (max + 1);
        bucket[index][bucketSize[index]] = arr[i];
        bucketSize[index]++;
    }

    int indexResult = 0;

    for(int i = 0; i < len; i++){
        insertionsort(bucket[i], bucketSize[i]);

        for(int j = 0; j < bucketSize[i]; j++){
            arr[indexResult] = bucket[i][j];
            indexResult++;
        }
    }
}

int main(){
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};

    int len = sizeof(array) / sizeof(array[0]);

    bucketsort(array, len);

    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
