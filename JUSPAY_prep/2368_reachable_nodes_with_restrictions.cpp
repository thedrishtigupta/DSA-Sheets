


class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& blocked) {
        int ans = 1;

        for(int ch : adj[node]) {
            if(ch == parent || blocked[ch]) continue;
            ans += dfs(ch, node, adj, blocked);
        }

        return ans;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<vector<int>> adj(n);

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> blocked(n, false);

        for(int x : restricted)
            blocked[x] = true;

        if(blocked[0]) return 0;

        return dfs(0, -1, adj, blocked);
    }
};