//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int solve(vector<int>& arr, int n, int currsum, int& sum, vector<vector<int>>& dp) {
        if (n == 0) {
            return abs(sum - 2 * currsum);
        }
        if (dp[n][currsum] != -1) return dp[n][currsum];
        
        int include = solve(arr, n - 1, currsum + arr[n - 1], sum, dp);
        int not_include = solve(arr, n - 1, currsum, sum, dp);
        
        return dp[n][currsum] = min(include, not_include);
    }

    int minDifference(vector<int>& arr) {
        int sum = 0;
        for (auto x : arr) {
            sum += x;
        }
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return solve(arr, n, 0, sum, dp);
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends