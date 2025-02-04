//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to find length of longest increasing subsequence.
    int solve(vector<int>& arr, int i, int p, vector<vector<int>>& dp) {
        if (i >= arr.size()) return 0;

       
        if (p != -1 && dp[i][p + 1] != -1) return dp[i][p + 1];

        int pick = 0;
        if (p == -1 || arr[i] > arr[p]) {
            pick = 1 + solve(arr, i + 1, i, dp);
        }
        int not_pick = solve(arr, i + 1, p, dp);

      
        return dp[i][p + 1] = max(pick, not_pick);
    }

    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, 0, -1, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends