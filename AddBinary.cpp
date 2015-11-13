/*
 * 67 Add　Binary
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".""""""
 * */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string ret = "";
    auto ita = a.rbegin();
    auto itb = b.rbegin();
    int c = 0;
    while (ita != a.rend() && itb != b.rend()) {
        int d = *ita - '0' + *itb - '0' + c;
        int r = d % 2;
        ret += to_string(r);
        c = d / 2;
        ++ita;
        ++itb;
    }

    while (ita != a.rend()) {
        int d = *ita - '0' + c;
        int r = d % 2;
        ret += to_string(r);
        c = d / 2;
        ++ita;
    }
    while (itb != b.rend()) {
        int d = *itb - '0' + c;
        int r = d % 2;
        ret += to_string(r);
        c = d / 2;
        ++itb;
    }

    if (c)
        ret.push_back('1');

    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    string a = "1";
    string b = "11";

    cout << addBinary(a,b) << endl;
}
