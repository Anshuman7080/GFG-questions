//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int solve(string& s, int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            string str = s.substr(n - i, i);
            if (str[0] == '0') continue;

            int num = stoi(str);

            if (num > 0 && num < 27) {
                ans += solve(s, n - i);
            } else {
                break;
            }
        }

        return ans;
    }

    int countWays(string &s) {
        int n = s.length();
        return solve(s, n);
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.countWays(s);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends