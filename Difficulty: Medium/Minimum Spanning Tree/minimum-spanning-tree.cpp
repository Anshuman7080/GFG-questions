class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
     int cost=0;
     
     vector<int>ISMST(V,0),parent(V);
    
   priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0,{0,-1}});
        while(!pq.empty()){
            
            int wt=pq.top().first;
            int node=pq.top().second.first;
            int par=pq.top().second.second;
            pq.pop();
            
            if(!ISMST[node]){
                ISMST[node]=1;
                cost+=wt;
                parent[node]=par;
                
                for(int j=0;j<adj[node].size();j++){
                    if(!ISMST[adj[node][j][0]]){
                      pq.push({adj[node][j][1],{adj[node][j][0],node}});  
                    }
                }
                
            }
            
            
            
        }
        
        
        return cost;
        
    }
};