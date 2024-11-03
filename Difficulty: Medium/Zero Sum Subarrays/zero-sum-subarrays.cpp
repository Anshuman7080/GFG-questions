//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
       vector<long long >prefixSum;
      long long sum=0;
      
      
      unordered_map<int,int>mapi;
      for(int i=0;i<arr.size();i++){
          
          sum+=arr[i];
          prefixSum.push_back(sum);
         
          
      }
      
      int total=0;
      for(int i=0;i<prefixSum.size();i++){
          
         total+=mapi[prefixSum[i]];
         
         mapi[prefixSum[i]]++;
          
      }
      
      
      return total+mapi[0];
       
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends