#include<stdio.h>

void merge(int arr[], int l, int mid, int r){
    int n1 = mid +1-l;
    int n2 = r - mid;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    int i=0, j=0, k=l;
    while(i<=mid && j<=r){
        if(left[i] > right[j]){
            arr[k] = right[j];
            k++;
            j++;
        }
        else {
            arr[k] = left[i];
            i++;
            k++;
        }
    }
    while(i< mid){
        arr[k]= left[i];
        i++;
        k++;
    }
    while(j< mid){
        arr[k]= right[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
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
    mergeSort(arr, 0, num-1);
    for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}