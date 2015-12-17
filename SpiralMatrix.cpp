/*
 * 54 Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> & matrix)
{
    vector<int> ret;
    int m = matrix.size();
    if (m == 0)
        return ret;
    int n = matrix[0].size();
    int mark[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mark[i][j] = 0;
    int drt[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int num = 0;
    for (int i = 0; i <= (m - 1) / 2; ++i) {
        int x = i -1, y = i;
        for (int j = 0; j < 4; ++j) {
            x += drt[j][0];
            y += drt[j][1];
            while (x >= i && x < n-i && y >= i && y < m - i && mark[y][x] == 0) {
                ret.push_back(matrix[y][x]);
                mark[y][x] = 1;
                if (++num == n*m)
                    return ret;
                x += drt[j][0];
                y += drt[j][1];
            }
            x -= drt[j][0];
            y -= drt[j][1];
        }
    }
}

int main()
{
    vector<vector<int>> m = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ret = spiralOrder(m);
    for (auto & i :ret)
        cout << i << ",";
    cout << endl;
}
