// 最大子数组的乘积

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int maxProduct(vector<int> &nums)
{
	int n = nums.size();
	vector<pair<int,int>> dp(n); // dp[i]表示前ｎ个数的最大值和最小值
	dp[0].first = dp[0].second = nums[0]; // first表示最小，second保存最大
	int answer = dp[0].second;
	for (int i = 1; i < n; ++i)
	{
		// 分nums[i]正负讨论
		if (nums[i]>=0)
		{
			dp[i].first = min(nums[i] * dp[i-1].first,nums[i]);
			dp[i].second = max(nums[i], dp[i-1].second*nums[i]);
		}
		else
		{
			dp[i].first = min(nums[i], nums[i]*dp[i-1].second);
			dp[i].second = max(nums[i] * dp[i-1].first, nums[i]);
		}

		answer = max(dp[i].second, answer);
	}

	return answer;
}

int main()
{
	vector<int> nums = {-2,3,-4};
	cout << maxProduct(nums) << endl;
}
