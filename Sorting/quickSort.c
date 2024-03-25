#include<stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

}

int partition(int arr[], int low, int high){
    int pivot = low;
    int i=low, j=high;
    while (i<=high || low >= low)
    {
        if(arr[i] >arr[pivot] && arr[j]<arr[pivot]){
            if(i>j){
                swap(arr, pivot, j);
            }
            else
                swap(arr, i, j);
        }
        else{
            if(arr[i]<arr[pivot])
                i++;
            if(arr[j]>arr[pivot])
                j++;
        }   
    }
    return pivot;
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