//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(vector<int>&price,int i,vector<int>&dp){
      if(i==0)return 0;
      
      if(dp[i-1]!=-1)return dp[i-1];
      int ans=0;
      
      for(int j=1;j<=i;j++){
          int len=price[j-1]+solve(price,i-j,dp);
          
          ans=max(ans,len);
      }
      return dp[i-1]= ans;
      
  }
    int cutRod(vector<int> &price) {
       int n=price.size();
       vector<int>dp(n,-1);
       
       return solve(price,n,dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends