#include<iostream>
#include<list>
using namespace std;

class Graph{
    int vertices;
    list<int> *l;
    //array of list
    
public:
    Graph(int V){
        vertices=V;
        l=new list<int> [vertices];

        //the above line denotes that we want to create an array of 
        //lists.
    }

    void addEdge(int x, int y){
        //assuming a bidirectional connection

        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAll(){
        for(int i=0;i<vertices;i++){
            cout<<"Vertex "<<i<<" -> ";
            for(int nbr:l[i]){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(2,3);

    g.printAll();


    return 0;
}