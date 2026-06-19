
/*
1. build n-ary tree
2. perform dfs
3. calculate max time required using informTime array.
*/

class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime){
        int time = 0;
        for(auto& ch : adj[node]){
            time = max(time, dfs(ch, adj, informTime));
        }
        return informTime[node] + time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            if (manager[i] != -1) adj[manager[i]].push_back(i);
        }

        return dfs(headID, adj, informTime);
    }
};