//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int solve(int open, int close, int n, vector<vector<int>>&dp) {
        if (open == 0 && close == 0) return 1;

if(dp[open][close]!=-1)return dp[open][close];

        int first = 0, second = 0, third = 0, fourth = 0;
        if (open == n || open == close) {
            first = solve(open - 1, close, n,dp);
        }
        if (open == 0) {
            second = solve(open, close - 1, n,dp);
        }
        if (open != close && open != 0) {
            third = solve(open - 1, close, n,dp);
            fourth = solve(open, close - 1, n,dp);
        }

        return dp[open][close]= first + second + third + fourth;
    }

    int findCatalan(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n, n, n,dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        Solution obj;
        cout << obj.findCatalan(n) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends