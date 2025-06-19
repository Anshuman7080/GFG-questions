class Solution {
public:
    int findParent(int u, vector<int>& parent) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u], parent);
    }

    void UnionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++; 
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < V; i++) {
            for (auto& edge : adj[i]) {
                pq.push({edge[1], {i, edge[0]}});
            }
        }

        int cost = 0, edges = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            if (findParent(u, parent) != findParent(v, parent)) {
                cost += wt;
                UnionByRank(u, v, parent, rank);
                edges++;
            }
            
            if (edges == V - 1) break;
        }

        return cost;
    }
};
