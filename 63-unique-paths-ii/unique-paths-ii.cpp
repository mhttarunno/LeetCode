class Solution {
public:
    vector<vector<int>> dp;
    int gridDestination(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int up = gridDestination(i - 1, j, grid);
        int left = gridDestination(i, j - 1, grid);
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.assign(m, vector<int>(n, -1)); 
        return gridDestination(m - 1, n - 1, obstacleGrid);
    }
};