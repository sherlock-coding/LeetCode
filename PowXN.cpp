/*
 * 50 Pow(x,n)
 * Implement pow(x, n).
 * */

#include <iostream>
#include <cmath>

using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n == -1)
        return 1 / x;

    int newn = abs(n);
    double ret = 1;
    while (newn > 0) {
        if (newn & 1) ret *= x;
        x = x * x;
        newn >>= 1;
    }

    return n < 0 ?1 / ret : ret;
}

int main()
{
    double x = 0.00001;
    cout << myPow(x, 2147483647) << endl;
}
