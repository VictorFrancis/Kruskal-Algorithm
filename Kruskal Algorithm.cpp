#include<iostream>
#include<cstdlib>

using namespace std;

#define BLACK 1
#define WHITE 0


void create_graph(int nodes, int** &graph){

    graph=new int*[nodes];
}


void populate_graph(int nodes, int** &graph, int high, int low){

    int i, j;

    for(i=0; i<nodes; ++i){

        graph[i]=new int[nodes];

        for(j=0; j<nodes; ++j){
            if(i!=j){
                graph[i][j]=low+rand()%(high+1-low);
            }
            else{
                graph[i][j]=0;
            }
        }

    }
}


void display_graph(int nodes, int** graph){

    int i,j;
    for(i=0; i<nodes; ++i){
        for(j=0; j<nodes; ++j){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

}

void merge(int *A, int start, int finish){

    int i, j, k;
    int mid;

    mid=(start-finish)/2;

    i=start;
    j=mid+1;
    k=i;

    int temp[finish];

    while(i<=mid && j<=finish){

        if(A[i]<A[j]){

            temp[k++]=A[i++];

        }
        else{

            temp[k++]=A[j++];
        }
    }

    while(i<=mid){

        temp[k++]=A[i++];

    }
    while(j<=finish){

        temp[k++]=A[j++];
    }

    for(int i=start; i<=finish; i++){

        A[i]=temp[k];
    }


}

void merge_sort(int *A, int start, int finish){

    if(A[start]>=A[finish]){
        return;
    }

    int mid=(start-finish)/2;

    merge_sort(A,start,mid);
    merge_sort(A,mid+1,finish);

    merge_sort(A,start,finish);


	}

void create_sorted_edges(int nodes, int** graph, int* &parent, int* &sortedEdges, int* &color){

    sortedEdges=new int[nodes-1];
    parent=new int[nodes];
    color=new int[nodes];

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(graph[i][j]!=0){
                sortedEdges[i]=graph[i][j];
                parent[i]=i;
                color[i]=WHITE;
            }
        }
    }

    merge_sort(sortedEdges,0,nodes-1);


}


int main(){

    int nodes;
    int high, low;

    cout<<"Enter Nodes: ";
    cin>>nodes;

    cout<<"Enter high, low: ";
    cin>>high>>low;

    cout<<endl;

    int **graph;

    create_graph(nodes, graph);
    populate_graph(nodes, graph, high, low);
    display_graph(nodes, graph);

    cout<<endl;

    int *sortedEdges;
    int *parent;
    int *color;


    create_sorted_edges(nodes,graph,parent,sortedEdges,color);





}


