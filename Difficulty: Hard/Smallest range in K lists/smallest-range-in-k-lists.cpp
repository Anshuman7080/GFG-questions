//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range



class Solution {
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k) {
        pair<int, int> ans = {INT_MAX, INT_MIN};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
        int maxi = INT_MIN;
        
        for (int i = 0; i < k; i++) {
            p.push({arr[i][0], {i, 0}});
            maxi = max(maxi, arr[i][0]);
        }
        
        int range = INT_MAX;
        
        while (!p.empty() && p.size()>=k) {
            auto element = p.top();
            p.pop();
            int row = element.second.first;
            int col = element.second.second;
            
            if (range > maxi - element.first) {
                range = maxi - element.first;
                ans = {element.first, maxi};
            }
            
            if (col + 1 < n) {
                p.push({arr[row][col + 1], {row, col + 1}});
                maxi = max(maxi, arr[row][col + 1]);
            }
        }
        
        return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    
cout << "~" << "\n";
}   
	return 0;
}


// } Driver Code Ends