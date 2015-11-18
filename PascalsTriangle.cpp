/*
 * 118 Pascla's Triangle'
 * Given numRows, generate the first numRows of Pascal's triangle.'
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> v;
    for(int i = 0; i < numRows; ++i) {
        vector<int> row;
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || i == j)
                row.push_back(1);
            else 
                row.push_back(v[i-1][j] + v[i-1][j-1]);
        }
        v.push_back(row);
    }

    return v;
}

int main()
{
    vector<vector<int>> v = generate(5);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

