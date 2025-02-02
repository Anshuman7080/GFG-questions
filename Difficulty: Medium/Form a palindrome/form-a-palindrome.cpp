//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int findMinInsertions(string &s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMinInsertions(S) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends