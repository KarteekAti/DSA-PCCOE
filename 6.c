#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hash{
    int roll;
    long phone;
    struct hash* next;
};

struct hash *arr[10] = {NULL};

void search(int roll){
    int index = roll % 10;
    if(arr[index] != NULL){
        struct hash *temp = arr[index];
        while(temp->roll != roll && temp){
            temp = temp->next;
        }
        if(temp) printf("Phone: %d",temp->phone);
    }
}

void insert(int roll,long phone){
    int index = roll % 10;
    struct hash *node = (struct hash*)malloc(sizeof(struct hash));
    node->roll = roll;
    node->phone = phone;
    node->next = NULL;
    if(arr[index] == NULL){
        arr[index] = node;
    }
    else{
        struct hash *temp = arr[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = node;
    }
}

int main(){
    int n;
    printf("Enter number of Data\n");
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        int roll;
        long phone;
        printf("Enter roll and phone number\n");
        scanf("%d",&roll);
        scanf("%ld",&phone);
        insert(roll,phone);
    }
    search(173);
    return 0;
}