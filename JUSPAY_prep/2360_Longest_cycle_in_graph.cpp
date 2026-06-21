
/*
1.  To detect cycle in undirected graph, we keep an extra bool array, say inRecursion. 
    There is cycle in graph iff visited[i] && inRec[i] 
2.  To count the size of cycle , size = count[u] - count[v] + 1; 
    where u is the parent (from) node, and v is the child (to) node
*/
class Solution {
public:
    int ans = -1;
    void dfs(int u, vector<bool>& vis, vector<int>& count, vector<bool>& inRec, vector<int>& edges) {
        if (u == -1) return;

        vis[u] = true; inRec[u] = true;
        int v = edges[u];

        if(v != -1 && !vis[v]) {
            count[v] = count[u] + 1;
            dfs(v, vis, count, inRec, edges);
        } else if (v != -1 && inRec[v]) ans = max(ans, count[u] - count[v]+1);

        inRec[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<bool> vis(n, false), inRec(n, false);
        vector<int> count(n, 1);

        for(int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, vis, count, inRec, edges);
        }

        return ans;
    }
};