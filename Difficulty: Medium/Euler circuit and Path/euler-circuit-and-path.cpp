class Solution {
  public:
  
  void DFS(vector<int>&visited,vector<int> adj[],int node){
      visited[node]=1;
      
      for(int i=0;i<adj[node].size();i++){
          if(visited[adj[node][i]]==1)continue;
          DFS(visited,adj,adj[node][i]);
      }
      
      
  }
    int isEulerCircuit(int V, vector<int> adj[]) {
      
     vector<int>degree(V,0);
     for(int i=0;i<V;i++){
         degree[i]=adj[i].size();
     }
     int odd=0;
     
     for(int i=0;i<V;i++){
         if(degree[i]%2!=0){
             odd++;
         }
     }
     
     if(odd!=0 && odd!=2){
         return 0;
     }
     
     vector<int>visited(V,0);
   
   for(int i=0;i<V;i++){
       if(degree[i]!=0){
             DFS(visited,adj,i);
             break;
       }
   }
     
     
     bool flag=true;
     
     for(int i=0;i<V;i++){
         if(degree[i]!=0 && visited[i]==0){
             flag=false;
            return 0;
         }
     }
     
     if(odd==0 && flag){
         return 2;
     }
     if((odd==0 ||  odd==2) && flag){
         return 1;
     }
     
     return 0;
     
     
     
    }
};