/*
 * 204 Count Primes
 * Count the number of prime numbers less than a non-negative number, n.
 * */

#include <iostream>
#include <algorithm>

using namespace std;
// 求小于n的素数的个数
int countPrimes(int n)
{
    // 初始全为true
    bool isPrime[n];
    fill(isPrime, isPrime+n, true); 

    // 标记出不是prime的数，结束条件只需i*i<n
    for (int i = 2; i * i < n; ++i) {
        // 不是Prime下个数
        if (!isPrime[i])
            continue;
        // 从i*i开始标记
        for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 2; i < n; ++i)
        if (isPrime[i])
            ++cnt;

    return cnt;
}

int main()
{
    cout << countPrimes(4) << endl;
}
