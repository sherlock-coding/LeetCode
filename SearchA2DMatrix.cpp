/*
 * 74 Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target)
{
    if (matrix.size() == 0)
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, r = m * n;
    if (target < matrix[0][0] || target > matrix[m-1][n-1])
        return false;
    while (l < r) {
        int mid = l + (r-l)/2;
        if (matrix[mid/n][mid%n] == target)
            return true;
        else if (matrix[mid/n][mid%n] > target)
            r = mid;
        else
            l = mid+1;
    }

    return false;
}

int main()
{
    vector<vector<int>> m{{1}};
    cout <<searchMatrix(m, 0) <<endl;
}
