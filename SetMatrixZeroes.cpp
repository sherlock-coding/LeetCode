/*
 * 73 Set Matrix Zeroes
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * */

#include <iostream>
#include <vector>

using namespace std;

// O(m+n) space
void setZero(vector<vector<int> >& matrix) 
{
    int m = matrix.size();
    if (m == 0)
        return;
    int n = matrix[0].size();
    vector<bool> zeror(m, false);
    vector<bool> zeroc(n, false);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0)
                zeror[i] = zeroc[j] = true;
        }
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (zeror[i] || zeroc[j])
                matrix[i][j] = 0;
}

// O(1) space
// 第0行记录0-n-1列是否为0的信息
// 第0列记录1-m-1行是否为0的信息
// 另外记录第0行是否为0的信息
void setZeroOpt(vector<vector<int> >& matrix)
{
   int m = matrix.size();
   if (m == 0)
       return;
   int n = matrix[0].size();
   bool row0Zero = false;
   for (int i = 0; i < n; ++i) 
       if (matrix[0][i] == 0) {
            row0Zero = true;       
       }

   for (int i = 1; i < m; ++i) {
       for (int j = 0; j < n; ++j)
           if (matrix[i][j] == 0)
               matrix[0][j] = matrix[i][0] = 0;
   }

   for (int i = 1; i < m; ++i)
       for (int j = n-1; j >= 0; --j)
           if (matrix[0][j] == 0 || matrix[i][0] == 0)
               matrix[i][j] = 0;

   if (row0Zero) 
       for (int i = 0;i < n; ++i)
           matrix[0][i] = 0;
}

int main()
{
    
}
