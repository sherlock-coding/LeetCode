/*
 * 29 Divide Two Intergers
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 * */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <limits>

using namespace std;

int divide(int dividend, int divisor)
{
    if (divisor == 0) return numeric_limits<int>::max();
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1){
        if (dividend == numeric_limits<int>::min())
            return numeric_limits<int>::max();
        else
            return 0 - dividend;
    } 
        
    long long a = llabs(dividend);
    long long b = llabs(divisor);
    if (a < b)
        return 0;

    long long cnt = 0;
    while (a >= b) {
        long long btmp = b << 1;
        long long cnttmp = 0;
        while (a >= btmp) {
            ++cnttmp;
            btmp <<= 1;
        }
        cnt += 1 << cnttmp;
        a -= b << cnttmp;
    }

    bool flag;
    if ((dividend < 0 && divisor < 0) || (dividend > 0  && divisor> 0)) 
        flag = true;
    else
        flag = false;
    if (cnt == numeric_limits<int>::max())
        return numeric_limits<int>::max();
    else
        return flag?cnt : 0 - static_cast<int>(cnt);

}

int main()
{
    cout << divide(1026117192, -874002063) << endl;
}

