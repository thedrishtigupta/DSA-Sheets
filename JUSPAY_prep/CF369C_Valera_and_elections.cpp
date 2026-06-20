

#include <iostream>
#include<vector>
#include <utility>
#include<unordered_set>
using namespace std;

bool dfs(int node, int par, vector<vector<pair<int, int>>>& adj, unordered_set<int>& s) {
    bool inserted = false;
    for(auto& ch: adj[node]) {
        if (ch.first == par) continue;

        bool child = dfs(ch.first, node, adj, s);

        if(!child && ch.second == 2) {
            s.insert(ch.first);
            inserted = true;
        }
        inserted |= child;
    }
    return inserted;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;


    vector<vector<pair<int, int>>> adj(n+1);

    for(int i = 1; i < n; i++) {
        int a, b, t; cin>>a>>b>>t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    unordered_set<int> s;

    dfs(1, 0, adj, s);

    cout<<s.size()<<endl;
    for(auto& val : s) cout<<val<<" ";
    return 0;
}