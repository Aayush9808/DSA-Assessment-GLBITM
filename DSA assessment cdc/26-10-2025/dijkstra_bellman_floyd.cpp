#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src, int V) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto& [v, weight] : adj[u]) {
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

vector<int> bellmanFord(vector<Edge>& edges, int src, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    for(int i = 0; i < V - 1; i++) {
        for(Edge& e : edges) {
            if(dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }
    
    for(Edge& e : edges) {
        if(dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
            // Negative cycle detected
            return {};
        }
    }
    return dist;
}

vector<vector<int>> floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;
    
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}
