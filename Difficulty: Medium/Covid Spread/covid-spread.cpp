#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int helpaterp(vector<vector<int>> hospital) {
        int n = hospital.size();
        int m = hospital[0].size();
        queue<pair<int, int>> q;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hospital[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int cnt = 0;
        if (q.empty()) return 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false; 
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                int l = node.first;
                int j = node.second;
                q.pop();
                
                // Checking up
                if (l - 1 >= 0 && hospital[l - 1][j] == 1) {
                    q.push({l - 1, j});
                    hospital[l - 1][j] = 2;
                    spread = true;
                }
                
                // Checking down
                if (l + 1 < n && hospital[l + 1][j] == 1) {
                    q.push({l + 1, j});
                    hospital[l + 1][j] = 2;
                    spread = true;
                }
                
                // Checking left
                if (j - 1 >= 0 && hospital[l][j - 1] == 1) {
                    q.push({l, j - 1});
                    hospital[l][j - 1] = 2;
                    spread = true;
                }
                
                // Checking right
                if (j + 1 < m && hospital[l][j + 1] == 1) {
                    q.push({l, j + 1});
                    hospital[l][j + 1] = 2;
                    spread = true;
                }
            }
            if (spread) cnt++;
        }

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hospital[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};
