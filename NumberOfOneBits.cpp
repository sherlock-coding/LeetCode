/*
 * 191 Number of 1 Bits
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.''
 * */
#include <iostream>
#include <cstdint>

using namespace std;

int hammingWeight(uint32_t n)
{
    uint32_t mask = 0x1;
    int ret = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & mask)
            ++ret;
        mask <<= 1;
    }

    return ret;
}

int main()
{
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
}
