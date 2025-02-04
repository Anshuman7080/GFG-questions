//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int solve(vector<int>& arr, int ind, int prev, vector<vector<int>>& dp) {
        if (ind == arr.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int not_pick = solve(arr, ind + 1, prev, dp);
        int pick = INT_MIN;
        if (prev == -1 || arr[ind] > arr[prev]) {
            pick = arr[ind] + solve(arr, ind + 1, ind, dp);
        }

        return dp[ind][prev + 1] = max(pick, not_pick);
    }

    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, 0, -1, dp);
    }
};






//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends