/*
 * =====================================================================================
 *
 *       Filename:  N-QueensII.cpp
 *
 *    Description:  N皇后问题，求解的个数
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 15时23分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

/*************辅助函数************/

bool isFine(int row, int col, vector<int> &a)
{
    for ( int i = 0; i < row; ++i)
    {
        if ( a[i] == col || abs(a[i] - col) == row -i)
            return false;
    }
    return true;
}

/*************递归版本************/

void help(int row, int n, int &solution, vector<int> &a)
{
    for (int col = 0; col < n; ++col)
    {
        if (isFine(row, col, a))
        {
            a[row] = col;
            if (row == n-1)
                ++solution;
            else
            {
                a[row] = col;
                help(row+1, n, solution, a);
            }
        }
    }
}

int totalNQueensRecursively(int n)
{
    vector<int> a(n,0); // 标明每一行皇后的位置，a[2] = 4->表明第3行第5列放了皇后
    int solution = 0; // 解的个数
    help(0,n,solution,a);
    return solution;
}

/*********************************/

/*************迭代版本************/

int totalNQueensIteratively(int n)
{
    stack<pair<int, int>> s;
    vector<int> a(n,0);
    int solution = 0;
    s.push(make_pair(0,0));
    while (!s.empty())
    {
        pair<int,int> &now = s.top();
        while (now.second < n && !isFine(now.first,now.second,a))
            ++now.second;

        if (now.second < n)
        {
            a[now.first] = now.second;
            if (now.first == n-1)
            {
                ++solution;
                ++now.second;
            }
            else
            {
                s.push(make_pair(now.first+1, 0));
            }
        }
        else
        {
            s.pop();
            if (s.size() != 0)
                ++s.top().second;
        }
    }

    return solution;
}

/*********************************/


int main()
{
    int n = 8;
    int solution = totalNQueensRecursively(n);
    cout << solution << endl;
    int solution1 = totalNQueensIteratively(n);
    cout <<  solution1 << endl;
}
