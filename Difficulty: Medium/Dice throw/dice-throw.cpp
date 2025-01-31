//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int solve(int m,int n,int x, vector<vector<int>>&dp){
      if(n==0){
          if(x==0)return 1;
          else return 0;
      }
      if(dp[n][x]!=-1)return dp[n][x];
      
      int ans=0;
      
      
      for(int i=1;i<=m;i++){
         if(x>=i)ans+=solve(m,n-1,x-i,dp);
      }
      
      
     return dp[n][x]= ans; 
      
      
  }
    int noOfWays(int m, int n, int x) {
    
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
   return solve(m,n,x,dp);
    
    }
};




//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends