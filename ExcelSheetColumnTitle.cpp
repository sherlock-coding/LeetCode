/*
 * 168 Excel Sheet Column Title
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *         2 -> B
 *             3 -> C
 *                 ...
 *                     26 -> Z
 *                         27 -> AA
 *                             28 -> AB 
 * */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertToTitle(int n)
{
    string ret;
    while (n > 0) {
        n = n - 1;
        int r = n % 26;
        ret.push_back('A' + r);
        n = n / 26;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    for (int i = 1; i <= 55; ++i)
        cout << convertToTitle(i) << " ";
    cout << endl;
}
