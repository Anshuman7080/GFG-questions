//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int countSubsequences(int idx, bool hasA, bool hasB, bool hasC, string& s, vector<vector<vector<vector<int>>>>& dp) {
        int n = s.size();

        if (idx == n) {
            return hasC ? 1 : 0;
        }

        if (dp[idx][hasA][hasB][hasC] != -1) {
            return dp[idx][hasA][hasB][hasC];
        }

        int opt1 = 0, opt2 = 0;

        if (hasC) {
            if (s[idx] == 'c') {
                opt1 = countSubsequences(idx + 1, true, true, true, s, dp);
                opt1 += countSubsequences(idx + 1, true, true, true, s, dp);
            } else {
                opt2 = countSubsequences(idx + 1, true, true, true, s, dp);
            }
        } else if (hasB) {
            if (s[idx] == 'b') {
                opt1 = countSubsequences(idx + 1, true, true, false, s, dp);
                opt1 += countSubsequences(idx + 1, true, true, false, s, dp);
            } else if (s[idx] == 'c') {
                opt1 = countSubsequences(idx + 1, true, true, true, s, dp);
                opt1 += countSubsequences(idx + 1, true, true, false, s, dp);
            } else {
                opt2 = countSubsequences(idx + 1, true, true, false, s, dp);
            }
        } else if (hasA) {
            if (s[idx] == 'a') {
                opt1 = countSubsequences(idx + 1, true, false, false, s, dp);
                opt1 += countSubsequences(idx + 1, true, false, false, s, dp);
            } else if (s[idx] == 'b') {
                opt1 = countSubsequences(idx + 1, true, true, false, s, dp);
                opt1 += countSubsequences(idx + 1, true, false, false, s, dp);
            } else {
                opt2 = countSubsequences(idx + 1, true, false, false, s, dp);
            }
        } else {
            if (s[idx] == 'a') {
                opt1 = countSubsequences(idx + 1, true, false, false, s, dp);
            }
            opt2 = countSubsequences(idx + 1, false, false, false, s, dp);
        }

        return dp[idx][hasA][hasB][hasC] = (opt1 + opt2) % 1000000007; // Corrected modulo operation
    }

    int fun(string &s) {
        int n = s.length();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
        return countSubsequences(0, false, false, false, s, dp) % 1000000007; // Corrected modulo operation
    }
};




//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends