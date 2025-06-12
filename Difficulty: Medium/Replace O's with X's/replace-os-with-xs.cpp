// User function Template for C++

class Solution {
  public:
  int r,c;
  int row[4]={1,-1,0,0};
  int col[4]={0,0,1,-1};
  
  
  bool valid(int i ,int j){
      return i>=0 && i<r && j>=0 && j<c; 
  }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        
        int n=mat.size();
        int m=mat[0].size();
        r=n;
        c=m;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
             q.push({0,i});
             mat[0][i]='T';
            }
        }
        
         for(int i=1;i<n;i++){
            if(mat[i][0]=='O'){
             q.push({i,0});
             mat[i][0]='T';
            }
        }
        
          for(int i=1;i<m;i++){
            if(mat[n-1][i]=='O'){
             q.push({n-1,i});
             mat[n-1][i]='T';
            }
        }
        
        
         for(int i=1;i<m-1;i++){
            if(mat[i][m-1]=='O'){
             q.push({i,m-1});
             mat[i][m-1]='T';
            }
        }
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if (valid(i+row[k],j+col[k]) && mat[i+row[k]][j+col[k]]=='O'){
                     mat[i+row[k]][j+col[k]]='T';
                     q.push({i+row[k],j+col[k]});
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!='T'){
                    mat[i][j]='X';
                }else if(mat[i][j]=='T'){
                    mat[i][j]='O';
                }
            }
        }
        
        return mat;
    }
};