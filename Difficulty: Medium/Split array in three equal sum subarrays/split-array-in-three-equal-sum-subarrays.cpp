//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.



class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        vector<int> ans;
        if (arr.size() < 3) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        if (sum % 3 != 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int targetSum = sum / 3;
        int sum1 = 0;
        int sum2 = 0;
        int i = 0;
        int j = arr.size() - 1;
        for (; i < arr.size(); i++) {
            sum1 += arr[i];
            if (sum1 == targetSum) {
                break;
            }
        }
        for (; j >= 0; j--) {
            sum2 += arr[j];
            if (sum2 == targetSum) {
                break;
            }
        }
        if (i + 1 < j && sum - sum1 - sum2 == targetSum) {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
    }
};




//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends