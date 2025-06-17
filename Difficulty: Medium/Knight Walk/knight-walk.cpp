class Solution {
  public:
  int row[8]={2,2,-2,-2,1,-1,1,-1};
  int col[8]={1,-1,1,-1,2,2,-2,-2};
  bool valid(int i,int j,int n){
      return i>=0 && j>=0 && i<n && j<n;
  }
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Code here
        if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1])return 0;
        queue<pair<int,int>>q;
        vector<vector<bool>>chess(N,vector<bool>(N,false));
        q.push({KnightPos[0]-1,KnightPos[1]-1});
        chess[KnightPos[0]-1][KnightPos[1]-1]=1;
        
        int step=0;
        while(!q.empty()){

            int s=q.size();
            step++;
            
            for(int i=0;i<s;i++){
                 int j=q.front().first;
            int k=q.front().second;
            q.pop();
            
            for(int l=0;l<8;l++ ){
                int new_j=j+row[l];
                int new_k=k+col[l];
              
               if(valid(new_j,new_k,N) &&  !chess[new_j][new_k]){
                     if(new_j==TargetPos[0]-1 && new_k==TargetPos[1]-1)return step;
                   chess[new_j][new_k]=1;
                   q.push({new_j,new_k});
               } 
            }
            
            }
        }
        
        return -1;
    }
};