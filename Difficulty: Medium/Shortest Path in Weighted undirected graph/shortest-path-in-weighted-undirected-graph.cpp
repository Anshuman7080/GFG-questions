#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < m; i++) {
            adj[edges[i][0] - 1].push_back({edges[i][1] - 1, edges[i][2]});
            adj[edges[i][1] - 1].push_back({edges[i][0] - 1, edges[i][2]});
        }
        
        vector<int> path(n, -1);
        vector<int> dist(n, INT_MAX);
        vector<int> explored(n, 0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            if (explored[node]) continue;
            explored[node] = 1;
            
            for(auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                
                if (!explored[nextNode] && distance + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = distance + edgeWeight;
                    path[nextNode] = node;
                    pq.push({dist[nextNode], nextNode});
                } 
            }
        }

        if (dist[n-1] == INT_MAX) return {-1};

        vector<int> ans;
        int parent = n - 1;
        while (parent != -1) {
            ans.push_back(parent + 1);  
            parent = path[parent];
        }

ans.push_back(dist[n-1]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
