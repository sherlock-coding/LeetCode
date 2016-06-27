#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    if (nums.size() <=1)
        return nums;

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    for (int i = 1; i < n; ++i) {
        int curmax = 1;
        int index = -1;
        for (int j = i-1; j >= 0; --j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > curmax) {
                curmax = dp[j] + 1;
                index = j;
            }
        }

        dp[i] = curmax;
        prev[i] = index;
    }

    int retmax = 1;
    int endindex = 0;
    for (int i = 1; i < n; ++i)
        if (dp[i] > retmax) {
             retmax = dp[i];
             endindex = i;
        }

    vector<int> ret;
    while (retmax-- > 0) {
        ret.push_back(nums[endindex]);
        endindex = prev[endindex];
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ",";
    cout << endl;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(27);
    vector<int> ret = largestDivisibleSubset(nums);
    print(ret);
}
