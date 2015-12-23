/*
 * 77 Combinations
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

void combineHelp(vector<int> &a, int len, int n, int k, vector<vector<int>> &ret)
{
    int sz = a.size();
    if (sz == k)
        ret.push_back(a);
    else {
        if (len == n)
            return;
        int c[2] = {0, len + 1};
        for (int i = 0; i < 2; ++i) {
            if (c[i] == 0) 
                combineHelp(a, len+1, n, k, ret);
            else {
                a.push_back(c[i]);
                combineHelp(a, len+1, n, k, ret);
                a.pop_back();
            }
        }
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> a;
    combineHelp(a, 0,n,k,ret);

    return ret;
}

int main()
{
    vector<vector<int>> ret =  combine(4,2);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0 ; j < ret[i].size(); ++j) {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }
}
