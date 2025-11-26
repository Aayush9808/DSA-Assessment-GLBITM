#include <vector>
#include <list>
using namespace std;

bool detectCycleUndirected(vector<list<int>>& adj, int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(isCyclicUtil(adj, i, visited, -1)) return true;
        }
    }
    return false;
}

bool isCyclicUtil(vector<list<int>>& adj, int u, vector<bool>& visited, int parent) {
    visited[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(isCyclicUtil(adj, v, visited, u)) return true;
        } else if(v != parent) {
            return true;
        }
    }
    return false;
}

int countBridges(vector<list<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<int> disc(V), low(V), parent(V, -1);
    int time = 0, bridges = 0;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            bridgeUtil(adj, i, visited, disc, low, parent, time, bridges);
        }
    }
    return bridges;
}

void bridgeUtil(vector<list<int>>& adj, int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, int& time, int& bridges) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            parent[v] = u;
            bridgeUtil(adj, v, visited, disc, low, parent, time, bridges);
            
            low[u] = min(low[u], low[v]);
            
            if(low[v] > disc[u]) bridges++;
        } else if(v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}
