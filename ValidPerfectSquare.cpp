#include <iostream>

using namespace std;

bool isPerfectSquare(int num)
{
    if (num == 1 || num == 4)
        return true;

    int left = 1;
    int right = num;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid *mid == num)
            return true;
        else if (mid * mid < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    cout << isPerfectSquare(2147483647) << endl;
}
