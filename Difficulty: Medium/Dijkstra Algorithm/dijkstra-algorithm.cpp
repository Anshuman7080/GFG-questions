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

        int count = v;

        while (count--) {
            int node = -1;
            int value = INT_MAX;
            // Select a node which is not explored yet and its distance value is minimum
            for (int i = 0; i < v; i++) {
                if (!explored[i] && dist[i] < value) {
                    node = i;
                    value = dist[i];
                }
            }

            if (node == -1) break; 

            explored[node] = true;

            // Relax the edges
            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;

                if (!explored[neighbour] && dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
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