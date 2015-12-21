/*
 * 62 Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?'')'')
 * Note: m and n will be at most 100.
 * */

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && i == j) 
                dp[i][j] = 1;
            else {
                if (i - 1 >= 0)
                    dp[i][j] += dp[i-1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    cout << uniquePaths(3, 7) << endl;
}
