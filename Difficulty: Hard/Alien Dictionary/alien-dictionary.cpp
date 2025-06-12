
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        string ans="";
        string prev=words[0];
        vector<int> alphabet(26,0);
        int V=0;
        
        //For checking how many alphabets are present
        for(int i=0;i<words.size();i++){
            string w=words[i];
            for(int j=0;j<w.size();j++)
                alphabet[w[j]-'a']=1;
        }
        
        //Calculating number of vertices
        for(int i=0;i<26;i++){
            if(alphabet[i]==1)
                V=i+1;
        }
       
        vector<int> adj[V];
        vector<int> indegree(V,0);
        int flag=0;
        
        //Making adjacency list 
        for(int i=1;i<words.size();i++){
            string w = words[i];
            int len = min(prev.size(),w.size());
            for(int j=0;j<len;j++){
                if(prev[j]!=w[j]){
                     flag=1;
                    adj[prev[j]-'a'].push_back(w[j]-'a');
                    indegree[w[j]-'a']++;
                    break;
                }
            }
            
            //prev word is prefix of word w and has greater length
            if(!flag && prev.size()>w.size())
                return "";
            
            prev=words[i];
        }
       
       //Kahn's Algorithm
       queue<int> q;
       for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
       }
       
        
        vector<int> ans1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans1.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        //Checking cycle
        if(ans1.size()==V){
            for(auto it: ans1){
                //Checking if alphabet is present in dictionary or not
                if(alphabet[it]==1){ 
                    char ch = it+'a';
                    ans+=ch;
                }
            }
        }
        
        return ans;
    }
};