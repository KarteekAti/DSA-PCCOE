#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* l;
    struct node* r;
    struct node* next;
};

struct node* head = NULL;

struct node* insert(char d){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->l = NULL;
    temp->r = NULL;
    temp->next = NULL;
    return temp;
}

void push(struct node* n){
    if(head == NULL){
        head = n;
    }
    else{
        n->next = head;
        head = n;
    }
}

struct node* pop(){
    struct node* temp = head;
    head = head->next;
    return temp;
}

void inorder(struct node* temp){
    if(temp == NULL){
        return;
    }
    else{
        inorder(temp->l);
        printf("%c",temp->data);
        inorder(temp->r);
    }
}

int main(){
    char arr[] = { 'X' , 'Y' , 'Z' , '*' , '+' , 'W' , '/'};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    struct node *p, *q, *s;
    for(int i=0; i<n; ++i){
        if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/'  || arr[i] == '^'){
            s = insert(arr[i]);
            p = pop();
            q = pop();
            s->l = q;
            s->r = p;
            push(s);
        }
        else{
            s = insert(arr[i]);
            push(s);
        }
    }
    inorder(s);
    return 0;
}