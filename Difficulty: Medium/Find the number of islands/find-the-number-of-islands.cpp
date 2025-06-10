class Solution {
  public:
  
    int u[8] = {1,-1,0,0,1,-1,1,-1};
    int v[8] = {0,0,1,-1,1,-1,-1,1};
  
    void dfs(int r,int l,vector<vector<char>>& grid,
        vector<vector<bool>> &visited,int n,int m,int &count){
        visited[r][l] = true;
        count++;
        for(int i=0;i<8;i++){
            int row = u[i]+r;
            int col = v[i]+l;
            if(row>=0&&row<n&&col>=0&&col<m
                &&!visited[row][col]&&grid[row][col]=='L'){
                dfs(row,col,grid,visited,n,m,count);
                
            }
        }
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count=0;
        int isLandNumber = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count=0;
                if(!visited[i][j] && grid[i][j]=='L'){
                    dfs(i,j,grid,visited,n,m,count);
                    if(count>0)
                        isLandNumber++;
                }
            }
        }
        return isLandNumber;
    }
};
