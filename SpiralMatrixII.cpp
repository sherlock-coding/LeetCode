/*
 * 59 Spiral Matrix II
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *   [ 8, 9, 4 ],
 *    [ 7, 6, 5 ]
 *    ]
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int num = 1;
    for (int i = 0; i <= (n-1) / 2 && num <= n*n; ++i) {
        // 1、right
        for (int j = i; j < n - 1 - i && num <= n*n ; ++j) 
            ret[i][j] = num++;

        // 2、down
        for (int j = i; j < n - 1 - i && num <= n*n; ++j)
            ret[j][n-1-i] = num++;

        // 3、left
        for (int j = n - 1 - i ; j > i && num <= n*n; --j)
            ret[n-1-i][j] = num++;

        // 4、up
        for (int j = n - 1 - i ; j > i && num <= n*n; --j)
            ret[j][i] = num++;
    }
    if (num == n*n)
        ret[(n-1)/2][(n-1)/2] = num;

    return ret;
}

int main()
{
    vector<vector<int>> ret = generateMatrix(2);
    for (int i = 0; i < ret.size(); ++i)
    {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
