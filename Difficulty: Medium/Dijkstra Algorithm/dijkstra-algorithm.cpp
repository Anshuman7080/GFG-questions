//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int v = adj.size();
        vector<bool> explored(v, false);
        vector<int> dist(v, INT_MAX);

        dist[src] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
          p.push({0,src});      

       
        while (!p.empty()) {
            
            int node=p.top().second;
            p.pop();
            if(explored[node]){
                continue;
            }
  

            explored[node] = true;
            

            // Relax the edges
            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;

                if (!explored[neighbour] && dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                    p.push({dist[neighbour],neighbour});
                }
            }
        }

        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends