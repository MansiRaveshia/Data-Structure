//bidirected graph traversal with DEPTH FIRST SEARCH
#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void addedge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T source,map<T,bool> &visited){
        //recursive fun that will travel the graph
        cout<<source<<" ";
        visited[source]=true;
        //go to neighbour of that node thats not visited
        for(T nbr:l[source]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }

    void dfs(T source){
        map<T,bool> visited;
        //mark all nodes as not visited in beginning
        for(auto p:l){
            T node=p.first;
            visited[node]=false;
        }
        dfs_helper(source,visited);
    }
};

int main(){
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.dfs(0);
}