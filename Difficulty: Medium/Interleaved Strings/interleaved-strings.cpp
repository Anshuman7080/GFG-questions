//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int m,n,N;
  bool solve(int i,int j,int k,string&s1,string&s2,string&s3){
      if(i==m && j==n && k==N)return true;
      
      if(k>=N)return false;
      bool result=false;
      
      if(s1[i]==s3[k]){
          result=solve(i+1,j,k+1,s1,s2,s3);
      }
      
      if(result==true)return result;
      
      if(s2[j]==s3[k]){
          return solve(i,j+1,k+1,s1,s2,s3);
      }
      
      return result;
  }
    bool isInterleave(string& s1, string& s2, string& s3) {
        // Your code here
        m=s1.length();
        n=s2.length();
        N=s3.length();
        return solve(0,0,0,s1,s2,s3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        if (obj.isInterleave(a, b, c))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends