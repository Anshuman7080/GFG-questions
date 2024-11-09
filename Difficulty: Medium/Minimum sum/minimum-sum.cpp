//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        string ans = "";
        int carry = 0;
        int n = arr.size();
        int i = 0;

        while(i < n) {
            int num1 = arr[i];
            int num2 = (i + 1 != n) ? arr[i + 1] : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ans += to_string(sum % 10);
            i += (num2 != 0) ? 2 : 1;
        }

        if(carry != 0) {
            ans += to_string(carry);
        }

        std::reverse(ans.begin(), ans.end());
        
         while (ans.size() > 1 && ans[0] == '0') {
            ans.erase(ans.begin());
        }


        
        return ans;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends