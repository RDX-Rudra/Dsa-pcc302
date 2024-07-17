#include<stdio.h>
void bubbleSort(int arr[], int n){
    int swaped=1;
    for(int i=0; i<n-1 && swaped; i++){
        swaped = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaped = 1;
            }
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
    bubbleSort(arr, num);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}