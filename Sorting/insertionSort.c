#include<stdio.h>

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j=i;
        int temp = arr[i];
        while(arr[j-1]>temp && j>=1){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
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
    insertionSort(arr, num);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}