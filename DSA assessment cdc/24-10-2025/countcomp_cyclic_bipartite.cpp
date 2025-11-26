#include <vector>
#include <queue>
#include <list>
using namespace std;

int countConnectedComponents(vector<list<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int count = 0;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

void DFS(vector<list<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) DFS(adj, v, visited);
    }
}

bool isCyclic(vector<list<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    
    for(int i = 0; i < V; i++) {
        if(isCyclicUtil(adj, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

bool isCyclicUtil(vector<list<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(isCyclicUtil(adj, v, visited, recStack)) return true;
        } else if(recStack[v]) {
            return true;
        }
    }
    
    recStack[u] = false;
    return false;
}

bool isBipartite(vector<list<int>>& adj, int V) {
    vector<int> color(V, -1);
    
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                for(int v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
