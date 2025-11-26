#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if(rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if(rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

int kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    
    DisjointSet ds(V);
    int mstWeight = 0;
    
    for(Edge& e : edges) {
        int x = ds.find(e.src);
        int y = ds.find(e.dest);
        
        if(x != y) {
            mstWeight += e.weight;
            ds.unionSets(x, y);
        }
    }
    return mstWeight;
}

int primMST(vector<vector<pair<int,int>>>& adj, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    key[0] = 0;
    pq.push({0, 0});
    int mstWeight = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(inMST[u]) continue;
        inMST[u] = true;
        mstWeight += key[u];
        
        for(auto& [v, weight] : adj[u]) {
            if(!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return mstWeight;
}
