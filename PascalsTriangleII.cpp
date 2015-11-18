/*
 * 119 Pascal's Triangle II
 * Given an index k, return the kth row of the Pascal's triangle.'
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> cur;
    vector<int> pre;

    for (int i = 0; i <= rowIndex; ++i) {
        cur.clear();
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || i == j)
                cur.push_back(1);
            else 
                cur.push_back(pre[j-1] + pre[j]);
        }
        pre = cur;
    }

    return cur;

}

int main()
{
    vector<int> v = getRow(5);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
