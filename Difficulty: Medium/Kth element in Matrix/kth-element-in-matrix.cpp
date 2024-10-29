//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    
cout << "~" << "\n";
}
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  
  vector<pair<int,pair<int,int>>>temp;
  
  for(int i=0;i<n;i++){
      temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
  }
  
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
  
  int ans;
  
  pair<int,pair<int,int>>element;
  int i,j;
  
  
  while(k--){
      element=p.top();
      p.pop();
     ans=element.first;
     i=element.second.first;
     j=element.second.second;
     if(j+1<n)
     p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
     
     
     
  }
  
  
  return ans;
  
}
