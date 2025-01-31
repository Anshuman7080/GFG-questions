//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int sum, int ind,vector<vector<int>>&dp) {
        if (ind == 0) {
            return sum == 0 ? 0 : 1e9; 
        }
          if(dp[ind][sum]!=-1)return dp[ind][sum];
        int not_pick = solve(sum, ind - 1,dp);
        int pick = 1e9; 
        if (sum >= ind * ind) {
            pick = 1 + solve(sum - ind * ind, ind,dp); 
        }

        return dp[ind][sum]= min(pick, not_pick);
    }

    int MinSquares(int n) {
        vector<vector<int>>dp(sqrt(n)+1,vector<int>(n+1,-1));
        return solve(n, sqrt(n),dp);
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends