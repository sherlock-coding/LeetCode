/*
 * 171 Excel Sheet Column Number
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * */

#include <iostream>
using namespace std;

int titleToNumber(string s)
{
    int n = 0;
    for (auto& c : s) {
        n = (c - 'A') + n * 26 + 1;
    }

    return n;
}

int main()
{
    string s = "BA";
    cout << titleToNumber(s) << endl;
}
