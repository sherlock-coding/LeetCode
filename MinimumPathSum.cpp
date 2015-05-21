/*
 * =====================================================================================
 *
 *       Filename:  MinimumPathSum.cpp
 *
 *    Description:  二维数组路径最小和
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 16时13分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * 思路：
 * 1、枚举
 * m行n列。（m+n-2）步（m-1）步向下，（n-1）步向右，共C(m+n-2，m-1)步
 * 2、动态规划
 * dp[i][j]表示从左上走到（i，j）的最小值
 * dp[i][j] = min(dp[i-1][j], dp[i][j-1])+a[i][j]
 * 初值：
 * dp[0][0]=a[0][0]
 * dp[0][j>0] = dp[0][j-1]+a[0][j]
 * dp[i>0][0] = dp[i-1][0]+a[i][0]
 * 时间O(m*n),空间O(m*n)
 * 空间优化:省掉一维
 * dp[i][j]只与dp[i-1][j],dp[i][j-1]有关
 * 对于每个i，正向循环j，之前的dp[j-1]是新的，dp[j]还是旧的
 * dp[j] = min(dp[j-1],dp[j])+a[i][j]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0)
            {
                if (j == 0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else
            {
                if (j == 0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    return 0;
}
