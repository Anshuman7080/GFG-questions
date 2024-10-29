//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends




class Solution {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    void insertHeap(int &x) {
          if(leftMaxHeap.empty()){
            leftMaxHeap.push(x);
            return;
        }
        
        if(leftMaxHeap.top()<x){
            rightMinHeap.push(x);
        }else{
            leftMaxHeap.push(x);
        }
        
        balanceHeaps();

    }

    void balanceHeaps() {
         if(rightMinHeap.size()>leftMaxHeap.size()){
        leftMaxHeap.push(rightMinHeap.top());
      rightMinHeap.pop();
     }
     else{
         if(rightMinHeap.size()<leftMaxHeap.size()-1){
             rightMinHeap.push(leftMaxHeap.top());
             leftMaxHeap.pop();
         }
     }

    }

    double getMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        } else {
            double ans = leftMaxHeap.top() + rightMinHeap.top();
            ans /= 2;
            return ans;
        }
    }
};




//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends