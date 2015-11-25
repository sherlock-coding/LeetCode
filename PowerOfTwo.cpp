/* 
 * 231 Power of Two
 * Given an integer, write a function to determine if it is a power of two.
 * */

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n < 1)
        return false;
    int cnt = 0;
    while ( n > 0) {
        cnt += n & 0x1;
        if (cnt > 1)
            return false;
        n >>= 1;
    }

    return true;
}

int main()
{
    cout << isPowerOfTwo(6) << endl;
}
