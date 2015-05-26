// 求triangle中从顶部到底的最短路径

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle)
{
	int n = triangle.size();
	vector<vector<int> > dp(n, vector<int>(n,0));
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i-1][j];
			else if ( j == i)
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]);
			dp[i][j] += triangle[i][j];
		}
	}

	int answer = dp[n-1][0];
	for (int j = 1; j < n; ++j)
		if (dp[n-1][j] < answer)
			answer = dp[n-1][j];
	return answer;
}

// 空间优化至O(n)
int minimumTotal1(vector<vector<int> > &triangle)
{
	int n = triangle.size();
	vector<int> dp(n,0);
	dp[0] = triangle[0][0];
	
	for (int i = 1; i < n; ++i)
	{
		int last = dp[0];
		for (int j = 0; j <= i; ++j)
		{
			int tmp = dp[j]; // 旧的dp[j]
			if (j == 0)
				dp[j] = dp[j];
			else if (j == i)
				dp[j] = last;
			else
				dp[j] = min(dp[j],last);
			dp[j] += triangle[i][j];
			last = tmp;
		}
	}

	int answer = dp[0];
	for (int j = 1; j < n; ++j)
		if (dp[j] < answer)
			answer = dp[j];

	return answer;
}

int main()
{
	vector<vector<int> > triangle = { {2}, {3,4}, {6,5,7},{4,1,8,3}};

	cout << minimumTotal(triangle) << endl;
	cout << minimumTotal1(triangle) << endl;

}
