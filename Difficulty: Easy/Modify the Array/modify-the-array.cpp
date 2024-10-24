//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
      
       for(int i=1;i<arr.size();i++){
            int prev=arr[i-1];
            int curr=arr[i];
            if((prev==curr) && (prev*curr)!=0){
                arr[i-1]*=2;
                arr[i]=0;
            }
        }
           int i=0;
            for(int j=i;j<arr.size();j++){
            if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                    i++;
                }
            }
   return arr;
      
      
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends