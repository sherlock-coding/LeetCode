/*
 * 190 Reverse Bits
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 * */

#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    /*
    if (n == 0)
        return n;
    int b[32];
    fill(b, b+32, 0);
    int index = 0;
    while (n > 0) {
        b[index++] = n % 2;
        n = n / 2;
    }

    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i) {
        ret = ret * 2 + b[i];
    }

    return ret;
    */
    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i) {
        ret <<= 1;
        ret |= n & 1;
        n >>= 1;
    }

    return ret;
}

char tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

uint32_t reverseBitsOpt(uint32_t n)
{
    uint32_t ret = 0; 
    for (int i = 0; i < 8; ++i) {
        ret <<= 4;
        ret |= tb[n & 0xF];
        n >>=4;
    }

    return ret;
}

int main()
{
    uint32_t n = 1;
    cout << reverseBits(n) << endl;
    cout << reverseBitsOpt(n) << endl;
}
