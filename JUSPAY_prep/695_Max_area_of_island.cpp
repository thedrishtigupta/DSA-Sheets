

class Solution {
public:
    int dfs(int i, int j, int& n, int& m, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        int op1 = dfs(i-1, j, n, m, grid);
        int op2 = dfs(i+1, j, n, m, grid);
        int op3 = dfs(i, j-1, n, m, grid);
        int op4 = dfs(i, j+1, n, m, grid);

        return op1 + op2 + op3 + op4 + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    int area = dfs(i, j, n, m, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};