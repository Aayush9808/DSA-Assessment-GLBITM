#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

void BFS(vector<list<int>>& adj, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void DFS(vector<list<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(adj, v, visited);
        }
    }
}

void DFSIterative(vector<list<int>>& adj, int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        
        if(!visited[u]) {
            visited[u] = true;
            
            for(int v : adj[u]) {
                if(!visited[v]) {
                    s.push(v);
                }
            }
        }
    }
}
