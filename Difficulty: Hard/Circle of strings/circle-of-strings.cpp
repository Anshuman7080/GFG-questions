// User function Template for C++

class Solution {
  public:
  void DFS(int node,vector<int>adj[],vector<bool>&visited){
      visited[node]=1;
      for(int i=0;i<adj[node].size();i++){
          if(!visited[adj[node][i]]){
              DFS(adj[node][i],adj,visited);
          }
      }
  }
  
  
    int isCircle(vector<string> &arr) {
  
  vector<int>adj[26];
  int N=arr.size();
  vector<int>InDeg(26,0);
  vector<int>OutDeg(26,0);
  for(int  i=0;i<N;i++){
      string temp=arr[i];
      int u=temp[0]-'a';
      int v=temp[temp.size()-1]-'a';
      adj[u].push_back(v);
      OutDeg[u]++;
      InDeg[v]++;
  }
  //Elureian circuit
  // find indegree and outdegree
  
  for(int i=0;i<26;i++){
      if(InDeg[i]!= OutDeg[i])return 0;
  }
  
  
  // all edges are part of singe component
  
  vector<bool>visited(26,0);
 
  DFS(arr[0][0]-'a',adj,visited);
  
  for(int i=0;i<26;i++){
      if(InDeg[i] && !visited[i] ){
          return 0;
      }
  }
  
  return 1;
  
  
        
    }
};