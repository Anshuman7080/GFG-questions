//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xore = 0;
        for (long long int i = 0; i < N; i++) {
            xore ^= Arr[i];
        }
        
        long long int setbi = 0;
        while (!((xore) & (1 << setbi))) {
            setbi++;
        }
        
        long long int x = 0;
        long long int y = 0;
        for (long long int i = 0; i < N; i++) {
            if ((Arr[i] & (1 << setbi))) {
                x ^= Arr[i];
            } else {
                y ^= Arr[i];
            }
        }
        
        vector<long long int> ans;
        
        
        if(x>y){
             ans.push_back(x);
        ans.push_back(y);
        }else{
      
        ans.push_back(y);
          ans.push_back(x);
        }
        
        
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends