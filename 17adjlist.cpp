//weighted graph adjaceny list representation using hashmap
//here the vertex are any alphabets 
#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>> l;
    public:
    void addedge(string x,string y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printadjacencylist(){
        for(auto p:l){                  //p will store key value pair
            string city=p.first;        //city will store key
            list<pair<string,int>> nbrs=p.second;  //nbrs will store values in pair form of neighbour and weight of its connecting edge
            cout<<"neighbours of "<<city<<" are: ";
            for(auto nbr: nbrs){
                string destination=nbr.first;
                int dist=nbr.second;
                cout<<destination<<" "<<dist<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","D",true,30);
    g.addedge("A","C",true,10);
    g.addedge("C","D",true,40);
    g.addedge("A","D",false,50);
    g.printadjacencylist();
}