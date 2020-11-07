//ckeck if graph is cyclic or not using DFS approach
#include<iostream>
#include<list>
#include<map>
#include<queue>
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

    bool cycle_helper(int node,bool* visited,int parent){
        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                bool cycle_mila=cycle_helper(nbr,visited,node);
                if(cycle_mila){
                    return true;
                }
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }
    bool contain_cycle(){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        return cycle_helper(0,visited,-1);
    }
};
int main()
{
    Graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,0);
    cout<<g.contain_cycle();

}