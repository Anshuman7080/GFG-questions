class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int>visited(n,0);
        vector<int>ans(n,-1);
        
        
        queue<int>q;
        q.push(src);
        int cnt=0;
        ans[src]=0;
        visited[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                visited[adj[node][i]]=1;
                ans[adj[node][i]]=ans[node]+1;
                q.push(adj[node][i]);
                }
            }
        }
        
        return ans;
    }
};