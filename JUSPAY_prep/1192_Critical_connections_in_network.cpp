
/*
Tarjan's algorithm!!!

Bridge condition : if (low[v] > dt[u]); // Because without u(parent), we cannot visit v(child) node.
// So no matter how low low[v] is, it will always be greater than dt[u] since it goes through u!

1. dt[i] = discovery time of ith node
2. low[i] = lowest dt of all reachable nodes from i (including i)
3. time = variable used to update dt[] and low[]

            v
            |
    !visited     visited
                    |
        v = parU      v != parU

*/

class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int par, vector<vector<int>>& adj, vector<vector<int>>& ans) {
        dt[u] = low[u] = ++time; // initially same!

        for(int v : adj[u]) {
            if (v == par) continue;

            if (dt[v] == -1) {
                dfs(v, u, adj, ans);
                low[u] = min(low[u], low[v]);

                if(low[v] > dt[u]) ans.push_back({u, v});
            } else if (v != par) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;

        vector<vector<int>> adj(n);

        for(auto& vec : connections) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        for(int i = 0; i < n; i++) {
            if (dt[i] == -1) dfs(i, -1, adj, ans);
        }

        return ans;
    }
};