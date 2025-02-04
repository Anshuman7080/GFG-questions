//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
public:
    int lcs(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int first = 0, second = 0, third = 0;

              
                if (s1[i - 1] == s2[j - 1]) {
                    first = 1 + dp[i - 1][j - 1];
                } else {
                    second = dp[i - 1][j];
                    third = dp[i][j - 1];
                }

                dp[i][j] = max(first, max(second, third));
            }
        }

       
        return dp[n1][n2];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends