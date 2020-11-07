//creating adjacency list of graph
//considering bidirected graph and vertex no from 0 to V-1
#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;  //l is pointer to array of list
    public:
    Graph(int V){     // V is no of vertices
        this->V=V;
        l=new list<int>[V];  //array of V link list
    }

    void addedge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printadjacencylist(){
        for(int i=0;i<V;i++){
            cout<<endl<<"Neighbour of vertex "<<i<<endl;
            for(int nbr:l[i]){
                cout<<nbr<<",";
            }
        }
    }
};

int main(){
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);
    g.printadjacencylist();
}

