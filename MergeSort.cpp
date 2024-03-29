#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
	// untuk cari size yang mau digabung
    int len = end - start + 1; 


	// temporary array yang kita gunakan untuk ganti ganti
    int temp[len];	

	// assign value temporary untuk temporary array kita
    int i = start, j = mid + 1, k = 0; 

	// kiri        kanan
    while(i <= mid && j <= end){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

	//untuk isi sisa sisa
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
	// assign temporary array balik ke si array asli
    for(int x = 0; x < len; x++){ 
    	// start + x?
    	// supaya ga overriding(nimpak)
        arr[start + x] = temp[x];
    }
}

void mergesort(int arr[], int start, int end){
    if(start < end){
        // Mencari indeks tengah bagian array
        int mid = (start + end) / 2;
        
        // bagian kiri
        mergesort(arr, start, mid);
        
		// bagian kanan
		mergesort(arr, mid + 1, end);
        
        // gabungin
        merge(arr, start, mid, end);
    }
}

int main(){
    // Array yang akan diurutkan
    int array[] = {2, 5, 8, 9, 10, 14, 16, 1, 5};
    
    int len = sizeof(array) / sizeof(array[0]);
	
// -1 supaya kena last index karena len nya merupakan size
// total size = 9 , tapi last index 8 makanya harus -1 
    mergesort(array, 0, len - 1);
    
    for(int x = 0; x < len; x++){
        printf("%d ", array[x]);
    }

    return 0;
}
	
