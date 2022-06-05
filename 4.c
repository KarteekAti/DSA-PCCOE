#include<stdio.h>

void merge(int arr[], int l, int mid, int h){
    int k = l;
    int n1 = mid-l+1;
    int n2 = h - mid;
    int i=0, j=0;
    int L[n1], R[n2];
    for(int i=0; i<n1; ++i) L[i] = arr[l+i];
    for(int i=0; i<n2; ++i) R[i] = arr[mid + 1 + i];
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergesort(int arr[], int l, int h){
    if(l < h){
        int mid = (l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){
    int arr[] = {5,7,1,2,45,8,122,7,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0; i<n; ++i){
        printf("%d ",arr[i]);
    }
}