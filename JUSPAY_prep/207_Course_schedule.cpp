

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> adj;

        for(auto& vec : prereq) {
            inDegree[vec[0]]++;
            adj[vec[1]].push_back(vec[0]);
        }

        queue<int> q;
        int cnt = 0;

        for(int i = 0; i < n; i++) if(!inDegree[i]) {q.push(i); cnt++;}

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v : adj[u]) {
                inDegree[v]--;

                if(!inDegree[v]) {q.push(v); cnt++;}
            }
        }

        return cnt == n;
    }
};