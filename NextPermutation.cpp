/*
 * 31 Next Permutation
 * mplement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    if (nums.size() < 2)
        return;

    int i;
    for (i = nums.size() - 1; i >= 0; --i) {
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        if (nums[i-1] < nums[i]) {
            break;
        }
    }

    for (int j = nums.size() - 1; j >= i; --j) {
        if (nums[j] > nums[i-1]) {
            swap(nums[i-1], nums[j]);
            reverse(nums.begin()+i, nums.end());
            break;
        }
    }
}

int main()
{
    vector<int> v {1,2,3};
    while (1) {
        int a;
        cin >> a;
        nextPermutation(v);
        for (auto &n : v)
            cout << n <<",";
        cout << endl;
    }
}
