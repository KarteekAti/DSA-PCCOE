#include<stdio.h>
#include<stdlib.h>

struct Knap {
    int id;
    int p;
    int w;
    float pbw;
};


int main(void){
    int n,cap;
    printf("Enter Number of Items\n");
    scanf("%d",&n);
    printf("Enter Capacity of Bag\n");
    scanf("%d",&cap);
    struct Knap arr[n];
    for(int i=0; i<n; ++i){
        int p,w;
        printf("Item number: %d\n",i+1);
        printf("    Profit: "); scanf("%d",&p);
        printf("    Weight: "); scanf("%d",&w);

        arr[i].id = i+1;
        arr[i].p = p;
        arr[i].w = w;
        arr[i].pbw = (float) p/w;
    }

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(arr[i].pbw < arr[j].pbw){
                struct Knap temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }
    float total = 0;
    printf("\n\n Selected Items: \n\n");

    for(int i=0; cap>0 && i<n; ++i){
        int weight = 0;
        float profit = 0;
        if(cap > arr[i].w){
            profit = arr[i].p;
            weight = arr[i].w;
            cap -= arr[i].w;
        }
        else{
            weight = cap;
            profit = arr[i].pbw  * cap;
            cap = 0;
        }
        total += profit;
        printf("Item : %d\n",arr[i].id);
        printf("Profit : %.2f\n",profit);
        printf("Weight : %d/%d\n",weight,arr[i].w);
        printf("\n\n");
    }
    printf("Total Profit : %.2f\n",total);
    return 0;
}