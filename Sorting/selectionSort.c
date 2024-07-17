#include<stdio.h>

void selectionSort(int arr[], int n){
    int minIndex;
    for(int i=0; i<n-1; i++){
        minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]< arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex !=i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    selectionSort(arr, num);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}