
/*
1. build undirected graph
2. perform dfs
3. special condition : check if child == parent (common in unidrected graph), skip
4. count time as summation

Cases: 
A. no apples in tree -> dont add
B. Child subtree have apple -> add subtree time + 2 of child
C. Child have apple -> add 2

Note: walking 1 edge = 2 unit time
Note: Root node will take 0 unit time.
Ans = Summation of time from all child nodes.

Note: Building directed tree is failing testcases!
*/

class Solution {
public:
    int dfs(int node, int par, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;
        for(auto& ch : adj[node]) {
            if (ch == par) continue;
            int childTime = dfs(ch, node, adj, hasApple);
            if (childTime > 0 || hasApple[ch]) time += childTime + 2;
        } 
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        return dfs(0, -1, adj, hasApple);
    }
};