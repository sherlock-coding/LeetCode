/*
 * 202 Happy Number
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.""
 * */

#include <iostream>

using namespace std;

int getnext(int n)
{
    int ret = 0;
    while (n > 0) {
        int r = n % 10;
        ret += r * r;
        n = n / 10;
    }

    return ret;
}

bool isHappy(int n) 
{
    int next = getnext(n);
    while (next != 1) {
        if (next == 4)
            return false;
        next = getnext(next);
    }

    return true;
}

int main()
{
    cout << isHappy(11) << endl;
    cout << isHappy(19) << endl;
}

