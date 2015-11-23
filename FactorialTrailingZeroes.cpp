/*
 * 172 Factorial Trailing Zeroes
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
#include <cmath>

using namespace std;

int trailingZeroes(int n) 
{
    int ret = 0;
    while (n > 0) {
        int tmp = n / 5;
        ret += tmp;
        n = tmp;;
    }

    return ret;
}


int main()
{
    cout << trailingZeroes(1808548329) << endl;
}
