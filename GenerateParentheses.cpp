/*
 * 22 Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"""""""""""
 * */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(string& a, int k, int n, vector<string> & ret)
{
    int llen = count(a.begin(), a.end(), '(');
    int rlen = a.size() - llen;
    if (rlen > llen)
        return;
    string c; // candidate

    if (k == 2 * n)
        ret.push_back(a);
    else {
        if (llen < n)
            c.push_back('(');
        if (rlen < n)
            c.push_back(')');
        for (int i = 0; i < c.size(); ++i) {
            a.push_back(c[i]);
            backtrack(a, k + 1, n, ret);
            a.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ret;
    string a;
    if (n > 0)
        backtrack(a, 0, n, ret);

    return ret;
}

int main()
{
    for (auto s : generateParenthesis(3))
        cout << s << endl;
}
