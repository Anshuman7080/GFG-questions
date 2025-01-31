//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
  int solve(vector<int>&arr,int sum,int ind, vector<vector<int>>&dp){
      if(ind==0){
          if(sum%arr[0]==0)return 1;
          else return 0;
      }
      if(dp[ind][sum]!=-1){
          return dp[ind][sum];
      }
      int not_pick=solve(arr,sum,ind-1,dp);
       int pick=0;
      if(sum>=arr[ind]){
           pick=solve(arr,sum-arr[ind],ind,dp);
      }
      
      return dp[ind][sum]= pick+not_pick;
      
  }
    int count(vector<int>& coins, int sum) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(coins,sum,n-1,dp);
        
        
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends