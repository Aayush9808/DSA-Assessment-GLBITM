#include <vector>
#include <stack>
#include <list>
using namespace std;

void topologicalSort(vector<list<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> s;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            topologicalSortUtil(adj, i, visited, s);
        }
    }
}

void topologicalSortUtil(vector<list<int>>& adj, int u, vector<bool>& visited, stack<int>& s) {
    visited[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            topologicalSortUtil(adj, v, visited, s);
        }
    }
    s.push(u);
}

vector<int> topologicalSortKahn(vector<list<int>>& adj, int V) {
    vector<int> indegree(V, 0);
    for(int u = 0; u < V; u++) {
        for(int v : adj[u]) {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    return result;
}

int countStronglyConnectedComponents(vector<list<int>>& adj, int V) {
    stack<int> s;
    vector<bool> visited(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            fillOrder(adj, i, visited, s);
        }
    }
    
    vector<list<int>> transpose = getTranspose(adj, V);
    fill(visited.begin(), visited.end(), false);
    
    int count = 0;
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        
        if(!visited[u]) {
            DFS(transpose, u, visited);
            count++;
        }
    }
    return count;
}

void fillOrder(vector<list<int>>& adj, int u, vector<bool>& visited, stack<int>& s) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) fillOrder(adj, v, visited, s);
    }
    s.push(u);
}

vector<list<int>> getTranspose(vector<list<int>>& adj, int V) {
    vector<list<int>> transpose(V);
    for(int u = 0; u < V; u++) {
        for(int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }
    return transpose;
}
