/*
 * =====================================================================================
 *
 *       Filename:  MaximumSubarray.cpp
 *
 *    Description:  最大子数组和
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 16时39分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 *思路：
 *1、暴力枚举
 时间O(n^3)
 *2、聪明枚举
 时间O(n^2)
 *3、分治
 时间O(nlogn)
 *4、动态规划
 时间O(n)
 *5、另外一种线性枚举
 sum[i] = a[0]+a[1] +...+a[i]
 sum[-1] = 0;
对0<=i<=j
a[i]+a[i+1] +..+a[j] = sum[j]-sum[i-1]
对j，我们可以取得当前的sum[j],取得i-1一定是之前的最小的sum值，用一个变量记录sum的最小值
时间O(n),空间O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 聪明枚举
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = 1<<31;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i;j < n; ++j)
        {
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

// 分治
int maxSubArray1(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int mid = n >> 1;
    vector<int> lnum(nums.begin(), nums.begin()+mid);
    vector<int> rnum(nums.begin()+mid, nums.end());
    int answer = max(maxSubArray1(lnum), maxSubArray1(rnum));

    int sum = nums[mid-1];
    int maxSum = sum;
    for (int i = mid-2; i >= 0; --i)
        maxSum = max(maxSum, sum += nums[i]);
    sum = maxSum;
    for (int i = mid; i < n; ++i)
        maxSum = max(maxSum, sum += nums[i]);
    
    return max(maxSum, answer);
}

// 动态规划
int maxSubArray2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int answer = nums[0];

    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        answer = max(dp[i], answer);
    }

    return answer;
}

// 动态规划空间优化
int maxSubArray3(vector<int> &nums)
{
    int n = nums.size();
    int answer = nums[0];
    int endhere = nums[0];

    for (int i = 1; i < n; ++i)
    {
        endhere = max(nums[i], endhere+nums[i]);
        answer = max(endhere, answer);
    }

    return answer;
}

// 另外一种线性枚举
int maxSubArray4(vector<int> &nums)
{
    int n = nums.size();
    int minSum = min(0,nums[0]);
    int maxSum = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; ++i)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum-minSum);
        minSum = min(sum,minSum);
    }

    return maxSum;
}

int main()
{
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray4(a) << endl;

    return 0;
}
