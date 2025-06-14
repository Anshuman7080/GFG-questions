// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
vector<int>dist(V,1e8);
int e=edges.size();


dist[src]=0;

for(int i=0;i<V-1;i++){
    for(int j=0;j<e;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        if(dist[u]==1e8)continue;
        if(dist[u]+wt <dist[v]){
            dist[v]=dist[u]+wt;
        }
        
    }
}


for(int j=0;j<e;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
          if(dist[u]==1e8)continue;
        if(dist[u]+wt <dist[v]){
            
            //cycle detected
            return {-1};
           
        }
        
    }


return dist;
        
    }
};
