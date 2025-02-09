//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int palindromicPartition(string &s) {
        int n = s.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (isPalindrome(i, n - 1, s)) {
                dp[i] = 0;
            } else {
                for (int j = i; j < n - 1; j++) {
                    if (isPalindrome(i, j, s)) {
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }
        return dp[0];
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends