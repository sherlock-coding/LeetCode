// 字符串回文分割

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minCut(string s)
{
	int n = s.size();
	vector<vector<int> > mark(n, vector<int>(n, 0));
	for (int len = 1; len <= n; ++len)
	{
		for (int i = 0; i+len <= n; ++i)
		{
			int j = i + len - 1;
			if (s[i] == s[j] && (j-i <= 2 || mark[i+1][j-1]))
				mark[i][j] = 1;
		}
	}

	vector<int> dp(n+1, 0);
	for (int j = 2; j <= n; ++j)
	{
		dp[j] = j-1;
		if (mark[0][j-1])
		{
			dp[j] = 0;
			continue;
		}
		for (int i = 1; i <= j; ++i)
		{
			if (mark[i-1][j-1])
			{
				dp[j] = min(dp[j],dp[i-1]+1);	
			}
		}
	}

	return dp[n];

}


int main()
{
	string s = "aab";

	cout << minCut(s) <<endl;
}
