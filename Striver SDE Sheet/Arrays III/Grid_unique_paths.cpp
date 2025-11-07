
/*
This is a simple recursion/ DP question.
But we can do it using combination formula also, because we can say we only have two options, right and down
and everytime to reach the end, it takes, m+n-2 steps.
Therefore, n = m+n-2, r = m-1 or n-1 (nCr)
*/

#include <iostream>
#include<vector>
using namespace std;

int gridRec(int n, int m, int i = 0, int j = 0) {
    if(i == n-1 && j == m-1) return 1;
    if(i >= n || j >= m) return 0;

    return gridRec(n, m, i+1, j) + gridRec(n, m, i, j+1);
}

int gridDP(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int gridComb(int n, int m) {
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}
int main() {
    int n, m; cin>>n>>m;

    cout<<gridComb(n, m);
    return 0;
}