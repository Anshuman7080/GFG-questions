//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dp[1001][1001];

    int solve(int arr[], int n, int start, int end, int chance){
        if(start > end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];

        if(chance == 0){
            int left = arr[start] + solve(arr, n, start+1, end, chance^1);
            int right = arr[end] + solve(arr, n, start, end-1, chance^1);
            return dp[start][end] = max(left, right);
        }
        else {
            int left = solve(arr, n, start+1, end, chance^1);
            int right = solve(arr, n, start, end-1, chance^1);
            return dp[start][end] = min(left, right);
        }
    }

    bool is1winner(int n, int arr[]) {
        memset(dp, -1, sizeof(dp));
        int sum2 = 0, sum1 = 0;
        for(int i = 0; i < n; i++)
            sum2 += arr[i];

        sum1 = solve(arr, n, 0, n-1, 0);
       
        return sum1 >= (sum2 - sum1);
    }
};




//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends