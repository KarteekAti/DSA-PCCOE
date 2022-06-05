#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5

int minKey(bool mstSet[],int key[]){
    int min = INT_MAX, minInd = 0;
    for(int i=0; i<V; ++i){
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            minInd = i;
        }
    }
    return minInd;
}

void printMST(int parent[], int graph[V][V]){
    printf("Edge \tWeight\n");
    int cost = 0;
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Minimum Cost : %d",cost);
}

void primMST(int graph[V][V]){
    bool mstSet[V];
    int parent[V];
    int key[V];

    for(int i=0; i<V; ++i){
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; ++count){
        int u = minKey(mstSet,key);
        mstSet[u] = true;
        for(int j=0; j<V; ++j){
            if(graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]){
                parent[j] = u, key[j] = graph[u][j]; 
            }
        }
    }
    printMST(parent,graph);
}

int main(){
    int graph[V][V] =  { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}
