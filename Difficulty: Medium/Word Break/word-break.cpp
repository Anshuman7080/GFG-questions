//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution {
public:
    map<int, bool> mp;
    set<string> dict;

    bool solve(int i, string s) {
        if (i == s.size()) return true;
        if (mp.find(i) != mp.end()) return mp[i];

        for (int j = i; j < s.size(); j++) {
            string substr = s.substr(i, j - i + 1);
            if (dict.find(substr) != dict.end() && solve(j + 1, s)) {
                mp[i] = true;
                return true;
            }
        }

        mp[i] = false;
        return false;
    }

    int wordBreak(int n, string s, vector<string>& dictionary) {
        dict.insert(dictionary.begin(), dictionary.end());
        return solve(0, s) ? 1 : 0;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends