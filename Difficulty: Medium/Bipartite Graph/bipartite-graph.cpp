class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(const auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(V, -1);
        
        for (int start = 0; start < V; start++) {
            if (color[start] == -1) { 
                queue<int> q;
                q.push(start);
                color[start] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int i = 0; i < adj[node].size(); i++) {
                        int neighbor = adj[node][i];

                        if (color[neighbor] == -1) { 
                            color[neighbor] = 1 - color[node]; 
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false; 
                        }
                    }
                }
            }
        }
        return true;
    }
};
