//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings
    int solve(string&s1 ,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+solve(s1,s2,i-1,j-1,dp);
        }
        
        return dp[i][j]= max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
      int len=solve(s1,s2,n-1,m-1,dp);
      return n+m-len;
      
    }
};



//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends