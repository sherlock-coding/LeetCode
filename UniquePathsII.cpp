/*
 * 63 Unique Paths II
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.""
 * Note: m and n will be at most 100.
 * */

#include <iostream>
#include <vector>

using namespace std;

int uniquePahtsWithObstacles(vector<vector<int>> & obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) 
                continue;
            if (i == 0 && i== j)
                dp[i][j] = 1;
            if (i-1 >= 0)
                dp[i][j] += dp[i-1][j];
            if (j-1 >= 0)
                dp[i][j] += dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main()
{
}
