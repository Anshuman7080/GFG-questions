//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
      int ans=0;
      
      for(int i=0;i<arr.size();i++){
          ans=ans^arr[i];
      }
      
      if(ans!=0){
          return 0;
      }
      
      
    int n=arr.size();
   int val=1;
    
   for(int i=0;i<n-1;i++){
       val=(val*2)%1000000007;
   }
   
    
        return val-1;
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
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends