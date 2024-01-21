#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>

/*

Here, we will be traversing through all the nodes in a graph.
Not in a random order but like a level order traversal.
We take a source from the user and the nodes will be printed in order of distance
from the src.


Algo:
We create a queue,"q" and a map,"visited".
We here assume that Graph is already created and we only have to traverse it.
We start from src and push it into the queue.
Then we find the nbrs of q.front() and also push them.

We keep track of the pushed numbers by putting visited[q.front()]=true

we push only if it was never visited
We then cout the q.front() and pop it
This way we can traverse the while graph level-order.


*/
using namespace std;

class Graph
{
    int vertices;
    unordered_map<int, list<int>> map;

public:
    Graph(int V)
    {
        vertices = V;
    }

    void addEdge(int x, int y)
    {
        map[x].push_back(y);
        map[y].push_back(x);
    }

    void bfs(int src)
    {
        unordered_map<int, bool> visited;
        // for noting down, which keys are already visited

        queue<int> q;
        q.push(src);
        visited[src]=true;
        int level=0;

        while (!q.empty())
        {
            int node = q.front();
            for (int nbr:map[node])
            {
                if(visited[nbr]==false){
                    q.push(nbr);
                    visited[nbr]=true;
                }
                
            }
    
        //    cout<<"Level "<<level<<"-> ";
            cout<<node<<", ";
            q.pop();
        }
    }
};
int main()
{

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // Choosing 0 as the src for bfs traversal
    g.bfs(0);

    return 0;
}
