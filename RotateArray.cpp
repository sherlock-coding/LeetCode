/*
 * 189 Rotate Array
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateRightOne(vector<int>& nums)
{
    int sz = nums.size();
    int tmp = nums[sz-1];
    for (int i = sz-1; i > 0; --i)
        nums[i] = nums[i-1];
    nums[0] = tmp;
}

void solution1(vector<int>& nums, int k) 
{
    while (k-- > 0)
        rotateRightOne(nums);
}

void solution2(vector<int>& nums, int k)
{
    int leftk = nums.size() - k;
    reverse(nums.begin(), nums.begin()+leftk);
    reverse(nums.begin()+leftk, nums.end());
    reverse(nums.begin(), nums.end());
}

void solution3(vector<int>& nums, int k)
{
    int sz = nums.size();
    if (sz % k == 0) {
        for (int i = 0; i < k; ++i) {
            int cur = sz - 1 - i;
            int tmp = nums[cur];
            while (cur - k >= 0) {
                nums[cur] = nums[cur-k];
                cur -= k;
            }
            nums[cur] = tmp;
        }
    } else {
        int correct[sz];
        fill(correct, correct+sz, 0);
        for (int i = 0; i < k; ++i) {
            int cur = sz - 1 - i;
            if (correct[cur])
                continue;
            int tmp = nums[cur];
            while (cur != k - 1 - i) {
                nums[cur] = nums [(cur - k + sz) % sz];
                correct[cur] = 1;
                cur = (cur - k + sz) % sz;
            }
            nums[cur] = tmp;
            correct[cur] = 1;
        }
    }
}
void rotate(vector<int>& nums, int k)
{
    int sz = nums.size();
    k = k % sz;
    if ( k == 0)
        return;
    solution3(nums, k);    
}

int main()
{
    vector<int> v{1,2,3,4,5,6};
    rotate(v,4);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
