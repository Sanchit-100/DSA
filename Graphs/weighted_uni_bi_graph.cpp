#include<iostream>
#include<list>
#include<unordered_map>
#include<string>

using namespace std;

class Graph{
    int vertices;
    unordered_map<string,list<pair<string,int>>> map;

public:

    Graph (int V){
        vertices=V;
        
    }

    void addEdge(string a,string b ,bool bi,int weight){
        map[a].push_back(make_pair(b,weight));

        if(bi){
            map[b].push_back(make_pair(a,weight));
        }
    }

    void printAll(){
        for(auto i:map){
            //Note here that i will contain a pair of key and list of pairs
            //printing key

            cout<<i.first<<": ";

            //iterating over list
            for(auto j:i.second){
                cout<<j.first<<" "<<j.second<<"; ";
                //printing the name of city and the distance
            }

            cout<<endl;
        }
    }



};

int main(){
    Graph g(5);
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("D","C",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);


    g.printAll();


    return 0;
}