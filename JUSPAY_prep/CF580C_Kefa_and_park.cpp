



#include <iostream>
#include<vector>
using namespace std;

int dfs(int node, int par, int count, int m, vector<vector<int>>& adj, vector<int>& hasCat) {
    if(hasCat[node]) count++;
    else count = 0;

    if(count > m) return 0;

    bool isLeaf = true;
    int ans = 0;

    for(auto ch : adj[node]) {
        if(ch == par) continue;
        isLeaf = false;
        ans += dfs(ch, node, count, m, adj, hasCat);
    }

    return isLeaf ? 1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>>n>>m;

    vector<int> hasCat(n+1);
    for(int i = 1; i <= n; i++) cin>>hasCat[i];

    vector<vector<int>> adj(n+1);

    for(int i = 1; i < n; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<dfs(1, 0, 0, m, adj, hasCat);
    return 0;
}