class Solution {
  public:
  
  void solve(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans){
    visited[node]=1;
    ans.push_back(node);
    for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]){
            visited[adj[node][j]]=true;
            solve(adj[node][j],adj,visited,ans);
        }
    }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
      vector<bool>visited(n,0);
      
      
      vector<int>ans;
      solve(0,adj,visited,ans);
      return ans;
        
    }
};