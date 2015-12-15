/*
 * 48 Rotate Image
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 * */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> & matrix) 
{
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j <= i; ++j) 
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < matrix.size(); ++i) 
        for (int j = 0; j < matrix.size() / 2; ++j) 
            swap(matrix[i][j], matrix[i][matrix.size() - j -1]);
}

int main()
{

}
