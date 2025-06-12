class Solution {
  public:
    vector<int> findOrder(int N, vector<vector<int>> prerequisites) {

int P=prerequisites.size();
  vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        for (int i = 0; i < P; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int>ans;
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            cnt++;
            for (int i = 0; i < adj[node].size(); i++) {
                indegree[adj[node][i]]--;
                if (indegree[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        if(cnt<N)return {};
        
        return ans;
        
    }
};