
/*
Since, any node can have at most one child, no adj required.
*/
class Solution {
public:
    void dfs(int node, vector<int>& dist, vector<bool>& vis, vector<int>& edges) {
        vis[node] = true;

        int v = edges[node];

        if(v != -1 && !vis[v]) {
            vis[v] = true;
            dist[v] = 1 + dist[node];
            dfs(v, dist, vis, edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        vector<bool> vis1(n, false), vis2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, dist1, vis1, edges);
        dfs(node2, dist2, vis2, edges);

        int ansNode = -1, minD = INT_MAX;

        for(int i = 0; i < n; i++) {
            int maxD = max(dist1[i], dist2[i]);

            if(minD > maxD) {
                minD = maxD;
                ansNode = i;
            }
        }
        return ansNode;
    }
};