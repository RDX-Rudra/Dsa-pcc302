#include<stdio.h>




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