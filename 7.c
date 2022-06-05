#include<stdio.h>
int size = 0;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int a[], int i, int sz){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < sz && a[largest] < a[l]) largest = l;
    if(r < sz && a[largest] < a[r]) largest = r;
    if(largest != i){
         swap(&a[largest],&a[i]);
         heapify(a,i,sz);
    }
}


void insert(int a[], int n){
    if(size == 0) a[size++] = n;
    else{
        a[size++] = n;
        for(int i=(size/2)-1; i>=0; --i){
            heapify(a,i,size);
        }
    }
}

int main(){
    int a[10];
    insert(a,10);
    insert(a,20);
    insert(a,1);
    insert(a,5);
    insert(a,100);
    insert(a,25);
    insert(a,8);
    insert(a,24);
    insert(a,69);
    for(int i=0; i<size; ++i){
        printf("%d ",a[i]);
    }
    return 0;
}