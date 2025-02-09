//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[505][2005];
  
  int solve(int i,int rem,vector<int>&arr,int&k){
      if(i==arr.size())return 0;
      
      if(dp[i][rem]!=-1)return dp[i][rem];
      
      int ans;
      if(arr[i]>rem){
          ans=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
          
      }else{
          int choice1=(rem+1)*(rem+1)+solve(i+1,k-arr[i]-1,arr,k);
          int choice2=solve(i+1,rem-arr[i]-1,arr,k);
          ans=min(choice1,choice2);
      }
      dp[i][rem]=ans;
      return dp[i][rem];
      }
    int solveWordWrap(vector<int> arr, int k) {
       memset(dp,-1,sizeof(dp));
       return solve(0,k,arr,k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while (ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends