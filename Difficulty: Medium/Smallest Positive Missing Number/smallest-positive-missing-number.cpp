//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
       
       unordered_map<int,bool>mapi;
       int maxi=INT_MIN;
       for(int i=0;i<arr.size();i++){
           mapi[arr[i]]=true;
           if(arr[i]>maxi){
               maxi=arr[i];
           }
       }
        if(maxi<=0){
            return 1;
        }
       
       int ans;
       for(int i=1;i<=maxi;i++){
           if(!mapi[i]){
               ans=i;
               return ans;
           }
       }
       
  
       return maxi+1;
       
     
       
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends