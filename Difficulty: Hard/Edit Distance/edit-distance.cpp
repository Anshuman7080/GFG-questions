//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to compute the edit distance between two strings
    int solve(int i, int j, string& s1, string& s2,vector<vector<int>>&dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        int first = INT_MAX, second = INT_MAX, third = INT_MAX, fourth = INT_MAX;
             if(dp[i][j]!=-1)return dp[i][j];
        if (s1[i] == s2[j]) {
            first = solve(i - 1, j - 1, s1, s2,dp);
        } else {
            second = 1 + solve(i - 1, j - 1, s1, s2,dp);
            third = 1 + solve(i - 1, j, s1, s2,dp);
            fourth = 1 + solve(i, j - 1, s1, s2,dp);
        }

        return dp[i][j]= min(min(first, second), min(third, fourth));
    }

    int editDistance(string& s1, string& s2) {
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s1.length() - 1, s2.length() - 1, s1, s2,dp);
    }
};




//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends