//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
public:
    int getSingle(vector<int>& arr) {
        unordered_map<int, int> mapi;
        for (int i = 0; i < arr.size(); i++) {
            mapi[arr[i]]++;
        }
        
        for (auto val : mapi) {
            
            if (val.second % 2 != 0) {
                return val.first;
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends