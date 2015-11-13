/*
 * 66 Plus One
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    vector<int> ret;
    auto it = digits.rbegin();
    int c = 1;
    while (it != digits.rend()) {
         int a = (*it + c) % 10;
         c = (*it + c) / 10;
         ret.push_back(a);
         ++it;
    }
    if (c)
        ret.push_back(c);
    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    vector<int> v = {9};
    for (auto i : plusOne(v))
        cout << i << " ";
    cout << endl;
}
