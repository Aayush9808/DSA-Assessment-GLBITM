#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;
    
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void addDirectedEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void printGraph() {
        for(int i = 0; i < V; i++) {
            for(int v : adj[i]) {
                // print edge
            }
        }
    }
    
    int countVertices() {
        return V;
    }
    
    int countEdges() {
        int count = 0;
        for(int i = 0; i < V; i++) {
            count += adj[i].size();
        }
        return count / 2;
    }
};
