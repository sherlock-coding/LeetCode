/*
 * 80 Renive Dyokucates frin Sired Arrat II
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.'""
 * */

#include <vector>
#include <iostream>

using namespace std;

int remvoeDuplicates(vector<int>& nums)
{
    int sz = nums.size();
    if (sz < 3)
        return sz;

    int i = 0, j = 0;
    while (j < sz) {
        int prej = j;
        while ( j< sz-1 && nums[j] == nums[j+1]) ++j;
        if (j - prej + 1 > 2) {
            nums[i++] = nums[j];
            nums[i++] = nums[j];
        }
        else
            while (prej <= j)
                nums[i++] = nums[prej++];
        ++j;
    }            
    
    return i;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    cout << remvoeDuplicates(nums) << endl;
}
