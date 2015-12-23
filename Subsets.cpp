/*
 * 78 Subsets
 * iven a set of distinct integers, nums, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void help(vector<int>& a, int k, vector<int>& nums, vector<vector<int>> & ret)
{
    if (k == nums.size())
        ret.push_back(a);
    else {
        int i = k;
        while (i < nums.size()-1 && nums[i] ==nums[i+1]) ++i;
        int c = i - k +1;
        for (i = 0; i <= c; ++i) {
            if (i == 0) 
                help(a, k+c, nums, ret);
            else {
                a.insert(a.end(), i, nums[k]);
                help(a, k+c, nums, ret);
                a.erase(a.end()-i, a.end());
            }
        }
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<int> a;
    vector<vector<int>> ret;
    help(a, 0, nums, ret);
    return ret;
}

int main()
{
    vector<int> nums {1,2,3};
    vector<vector<int>> ret = subsets(nums);
    for (int i = 0; i < ret.size(); ++i)
    {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << ",";
        cout << endl;
    }
}
