/*
 * 69 Sqrt(x)
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 * */

#include <iostream>

using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1 || x == 2 || x == 3)
        return 1;
    int  low = 0, high = x;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long tmp = mid * mid;
        if (tmp == x) 
            return mid;
        if (tmp > x) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    long long ret = low;
    if (ret * ret > x)
        return ret - 1;

    return low;
}

int main() 
{
    cout << mySqrt(2147395599) << endl;
    cout << mySqrt(10) << endl;
    cout << mySqrt(225) << endl;
    cout << mySqrt(2) << endl;
    cout << mySqrt(8) << endl;
}

