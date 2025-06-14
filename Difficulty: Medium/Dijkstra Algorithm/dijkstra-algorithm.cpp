#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
     
     vector<vector<pair<int,int>>> adj(V);
     for(int i=0; i<edges.size(); i++){ 
         int u = edges[i][0];
         int v = edges[i][1];
         int weight = edges[i][2];
         adj[u].push_back({v, weight});
     }
     
     vector<bool> explored(V, false);
     vector<int> dist(V, INT_MAX);
     
     dist[src] = 0; 
     
    
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
     pq.push({0, src});
     
     while(!pq.empty()){
       
         while(!pq.empty() && explored[pq.top().second]) pq.pop();
         if (pq.empty()) break;

         int node = pq.top().second;
         pq.pop(); 
         explored[node] = true;
          
         for(int i=0; i<adj[node].size(); i++){
              int neighbor = adj[node][i].first;
              int weight = adj[node][i].second;
              if(!explored[neighbor] && dist[node] + weight < dist[neighbor]) {
                   dist[neighbor] = dist[node] + weight;
                   pq.push({dist[neighbor], neighbor});
              }
         }
     }
     
     for(int i=0;i<V;i++){
         if(dist[i]==INT_MAX){
             dist[i]=-1;
         }
     }
 
    return dist;
  }
};
