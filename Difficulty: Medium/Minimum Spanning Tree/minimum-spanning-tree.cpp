//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int u,vector<int>&parent){
	    if(u==parent[u]){
	        return u;
	    }
	    
	    return parent[u]=findParent(parent[u],parent);
	    // path compression
	    
	    
	}
	
	void unionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
	    
	    int pu=findParent(u,parent);
	    int pv=findParent(v,parent);
	    
	    
	    if(rank[pu]>rank[pv]){
	        parent[pv]=pu;
	    }else if(rank[pu]<rank[pv]){
	        parent[pu]=pv;
	    }
	    else{
	        parent[pv]=pu;
	        rank[pu]++;
	    }
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V);
       // parent will help us to determine set
       
       vector<int>rank(V,0);
       //rank will help us to merge set
       
       for(int i=0;i<V;i++){
           parent[i]=i;
       }
       
       
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;


        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                pq.push({adj[i][j][1],{i,adj[i][j][0]}});
                
            }
        }
        int cost=0;
        int edges=0;
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second.first;
            
            int v=pq.top().second.second;
            
            pq.pop();
            
            
            //check if they are in different set
            
            if(findParent(u,parent)!=findParent(v,parent)){
                cost+=wt;
                unionByRank(u,v,parent,rank);
                
                
            }
            
        }
        
        
        return cost;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends