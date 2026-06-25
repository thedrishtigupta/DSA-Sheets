

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> result;

        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);

        for(auto& vec : prereq) {
            adj[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
        }

        queue<int> q;
        int cnt = 0;

        for(int i = 0; i < n; i++) if(!inDegree[i]) {q.push(i); cnt++;}

        while(!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);

            for(auto& v : adj[u]) {
                inDegree[v]--;

                if(!inDegree[v]) {q.push(v); cnt++;}
            }
        }

        if (cnt != n) return {};

        return result;
    }
};