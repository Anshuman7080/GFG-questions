//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int get(int row, int col, vector<vector<int>>& mat, int n, int m, vector<vector<int>> &dp){
        
        if(row < 0 || col < 0 || row == n || col == m) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int dl = mat[row][col] + get(row+1, col-1, mat, n, m, dp);
        int dd = mat[row][col] + get(row+1, col, mat, n, m, dp);
        int dr = mat[row][col] + get(row+1, col+1, mat, n, m, dp);
    
        return dp[row][col] = max(dl, max(dd, dr));
        
    }

    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = INT_MIN;
        
        for(int i=0; i<m; i++){
            maxi = max(maxi, get(0, i, mat, n, m, dp));   
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends