#include<stdio.h>
#include<stdlib.h>
#define SIZE 500

int queue[SIZE]; int front = -1, rear = -1;

void dfs(int **edges,int n, int sv, int* visited){
    printf("%d ",sv);
    visited[sv] = 1;
    for(int i=0; i<n; ++i){
        if(i == sv) continue;
        if(edges[sv][i] == 1 && !visited[i]){
            dfs(edges,n,i,visited);
        }
    }
}

void add(int sv){
     if(rear == -1){
        queue[++rear] = sv;
        ++front;
    }
    else{
        queue[++rear] = sv;
    }
    // printf("%d ",queue[rear-1]); 
}

int delete(){
    if(front > rear || front == -1){
       return 0;
    }
    else{
       return queue[front++];
    }
}

void bfs(int **edges, int n, int sv, int *visited){
    visited[sv] = 1;
    add(sv);
    while(front <= rear && front != -1){
        int d = delete();
        printf("%d ",d);
        for(int i=0; i<n; ++i){
            if(edges[d][i] && !visited[i]){
                visited[i] = 1;
                add(i);
            }
        }
    }
    
}

int main(){
    int e,n;
    printf("Enter number of Edges and Verticies\n");
    scanf("%d",&e);
    scanf("%d",&n);
    int** edges = (int **)malloc(n*sizeof(int));
    for(int i=0; i<n; ++i){
        edges[i] = (int*)malloc(n*sizeof(int));
        for(int j=0; j<n; ++j){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; ++i){
        int f,s;
        printf("Enter first vertex and second vertex ");
        scanf("%d",&f);
        scanf("%d",&s);
        edges[f][s] = edges[s][f] = 1;
    }
    int *visited = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; ++i) visited[i] = 0;
    bfs(edges,n,0,visited);
    //dfs(edges,n, 0,visited);
    free(visited);
    free(edges);
}