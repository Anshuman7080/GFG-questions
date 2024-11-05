//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int findMatching(string text, string pat) {
        if(pat.length() > text.length()) {
            return -1;
        }
        size_t index = text.find(pat);
        if(index == string::npos) {
            return -1;
        }
        return index;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends