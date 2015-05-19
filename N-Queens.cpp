/*
 * =====================================================================================
 *
 *       Filename:  N-QueensII.cpp
 *
 *    Description:  N皇后问题，求所有解
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 19时23分23秒
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
#include <string>
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

void saveSolution(vector<vector<string>> &solutions, int n, vector<int> &a)
{
    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
        string s;
        for (int j = 0; j < n; ++j)
        {
            if (a[i] == j)
                s += "Q";
            else
                s += ".";
        }
        v.push_back(s);
        cout << s << endl;
    }
    solutions.push_back(v);
}

/*************递归版本************/

void help(int row, int n, int &solution, vector<vector<string>> &solutions, vector<int> &a)
{
    for (int col = 0; col < n; ++col)
    {
        if (isFine(row, col, a))
        {
            a[row] = col;
            if (row == n-1)
            {
                ++solution;
                saveSolution(solutions,n,a);
            }
            else
            {
                a[row] = col;
                help(row+1, n, solution, solutions, a);
            }
        }
    }
}

vector<vector<string>> solveNQueensRecursively(int n)
{
    vector<int> a(n,0); // 标明每一行皇后的位置，a[2] = 4->表明第3行第5列放了皇后
    int solution = 0; // 解的个数
    vector<vector<string>> solutions; // 解的具体图形分布
    help(0,n,solution,solutions,a);
    return solutions;
}

/*********************************/

/*************迭代版本************/

vector<vector<string>> solveNQueensIteratively(int n)
{
    stack<pair<int, int>> s;
    vector<int> a(n,0);
    int solution = 0;
    vector<vector<string>> solutions;
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
                saveSolution(solutions, n, a);
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

    return solutions;
}

/*********************************/


int main()
{
    int n = 8;
    vector<vector<string>> solutions = solveNQueensRecursively(n);
    cout << solutions.size() << endl;
    vector<vector<string>> solutions1 = solveNQueensIteratively(n);
    cout << solutions1.size() << endl;
}
