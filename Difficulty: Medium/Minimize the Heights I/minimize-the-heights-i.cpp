//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int getMinDiff(int k, vector<int>& arr) {
        // code hereint 
        int n = arr.size();
        if (n == 1) {
            return 0; 
        }
        
      sort(arr.begin(),arr.end());
        
      
        int initialDiff = arr[n - 1] - arr[0];
        int minDiff = initialDiff;
        
       
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        
      
        for (int i = 1; i < n; i++) {
            int minHeight = min(smallest, arr[i] - k);
            int maxHeight = max(largest, arr[i - 1] + k);
            minDiff = min(minDiff, maxHeight - minHeight);
        }
        
        return minDiff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends