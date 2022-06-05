#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 500

struct node{
    int data;
    struct node* l;
    struct node* r;
};



struct node* createnode(int d){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

struct node* insert(struct node *temp, int d){
    if(temp == NULL) return createnode(d);
    if(temp->data > d) temp->l = insert(temp->l,d);
    else temp->r = insert(temp->r,d);
    return temp;
}

struct node* delete(struct node* root, int d){
    if(root == NULL) return root;
    if(root->data > d){
        root->l = delete(root->l,d);
    }
    else if(root->data < d){
        root->r = delete(root->r, d);
    }
    else{
        if(root->l == NULL){
            struct node* temp = root->r;
            free(root);
            return temp;
        }
        else if(root->r == NULL){
            struct node* temp = root->l;
            free(root);
            return temp;
        }
        struct node* temp = root->r;
        while(temp && temp->l){
            temp = temp->l;
        }
        root->data = temp->data;
        root->r = delete(root->r,temp->data);
    }
    return root;
}

void display(struct node* root){
    if(root == NULL) return;
    else{
        display(root->l);
        printf("%d\n",root->data);
        display(root->r);
    }
}

void search(struct node* node,int d){
    if(node == NULL) printf("Data not Found\n");
    else if(node->data == d) printf("Data Found");
    else if(node->data > d) search(node->l,d);
    else search(node->r,d);
}

void mirror(struct node* root){
    if(root){
        mirror(root->l);
        mirror(root->r);
        struct node* temp = root->l;
        root->l = root->r;
        root->r = temp;
    }
    return;
}

int main(){
    struct node* root = NULL;
    root = insert(root,10);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,33);
    root = insert(root,32);
    root = insert(root,11);
    root = delete(root,10);
    mirror(root);
    display(root);
    search(root,20);
    return 0;
}