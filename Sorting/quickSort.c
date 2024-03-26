#include<stdio.h>

void swap(int *p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1; // Initialize i to the next index after pivot
    int j = high;

    while(i <= j) { // Change condition to <=
        while(arr[i] < pivot && i <= high) // Change condition to <
            i++;
        while(arr[j] > pivot && j >= low) // Change condition to >
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
        else
            break; // Break the loop when i and j cross each other
    }
    swap(&arr[j], &arr[low]);
    return j;
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