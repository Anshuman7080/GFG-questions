//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minValue(string s, int k) {
        unordered_map<char, int> mapi;
        
       
        for (int i = 0; i < s.length(); i++) {
            mapi[s[i]]++;
        }
        
       
        priority_queue<int> p;
        for (auto val : mapi) {
            p.push(val.second);
        }
        
        int ans = 0;
        while (k > 0 && !p.empty()) {
            int num = p.top();
            p.pop();
            if (num > 1) {
                num--;
                p.push(num);
            }
            k--;
        }
        
        
        while (!p.empty()) {
            int num = p.top();
            p.pop();
            ans += num * num;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends