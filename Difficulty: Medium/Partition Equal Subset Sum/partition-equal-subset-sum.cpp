//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool solve(vector<int>& arr, int sum, int ind, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (ind == 0) return arr[0] == sum;

        if (dp[ind][sum] != -1) return dp[ind][sum];

        bool not_pick = solve(arr, sum, ind - 1, dp);
        bool pick = false;
        if (sum >= arr[ind]) {
            pick = solve(arr, sum - arr[ind], ind - 1, dp);
        }

        return dp[ind][sum] = pick || not_pick;
    }

    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) sum += arr[i];

        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(arr.size(), vector<int>(sum / 2 + 1, -1));

        return solve(arr, sum / 2, arr.size() - 1, dp);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends