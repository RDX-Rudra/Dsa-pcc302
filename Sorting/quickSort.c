#include<stdio.h>

void swap(int *p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high){
    
}

void quickSort(int arr[], int low, int high){
    if(high>low){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int num;
    printf("Enter the number of element: ");
    scanf("%d", &num);
    int arr[num];
    for(int j=0; j<num; j++){
        scanf("%d", &arr[j]);
    }
    quickSort(arr, 0, num-1);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}