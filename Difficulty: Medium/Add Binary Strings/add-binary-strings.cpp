//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int i = n1 - 1;
        int j = n2 - 1;

        int sum = 0;
        int carry = 0;
        string str = "";

        while (i >= 0 && j >= 0) {
            sum = (s1[i] - '0') + (s2[j] - '0') + carry;
            if (sum <= 1) {
                carry = 0;
                str += to_string(sum);
            } else {
                carry = 1;
                str += to_string(sum - 2);
            }

            i--;
            j--;
        }

        while (i >= 0) {
            sum = (s1[i] - '0') + carry;
            if (sum <= 1) {
                carry = 0;
                str += to_string(sum);
            } else {
                carry = 1;
                str += to_string(sum - 2);
            }
            i--;
        }

        while (j >= 0) {
            sum = (s2[j] - '0') + carry;
            if (sum <= 1) {
                carry = 0;
                str += to_string(sum);
            } else {
                carry = 1;
                str += to_string(sum - 2);
            }
            j--;
        }

        if (carry != 0) {
            str += to_string(carry);
        }

        reverse(str.begin(), str.end());

      
        i = 0;
        while (i < str.length() && str[i] == '0') {
            i++;
        }

        str.erase(0, i);

        return str.empty() ? "0" : str;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends