//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int solve(vector<int>&arr,int i,int k,int n,bool purchase,vector<vector<vector<int>>>&dp){
      if(i==n || k==0)return 0;
      
      if(dp[i][k][purchase]!=-1){
          return dp[i][k][purchase];
      }
     int profit=0;
     
     if(purchase){
         profit=max(-arr[i]+solve(arr,i+1,k,n,false,dp),solve(arr,i+1,k,n,true,dp));
         
     }else{
         profit=max(arr[i]+solve(arr,i+1,k-1,n,true,dp),solve(arr,i+1,k,n, false,dp));
     }
     
     return dp[i][k][purchase]=profit;
  }
    int maxProfit(vector<int>& arr, int k) {
int n=arr.size();

vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(3,-1)));

return solve(arr,0,k,n,true,dp);

    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends