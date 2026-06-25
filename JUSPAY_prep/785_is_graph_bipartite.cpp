

class Solution {
public:
    bool bfs(int u, int col, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(u);
        color[u] = col;

        while(!q.empty()) {
            u = q.front(); q.pop();

            for(auto& v : graph[u]) {
                if(color[v] == color[u]) return false;

                if(color[v] == -1) {
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};