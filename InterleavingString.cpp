// 判断s3是否由s1和s2交叉而来
// dp[i][j]表示s3[1..i+j]是否s1[1..i]和s[1...j]交叉而来

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
	int m = s1.size();
	int n = s2.size();
	if (m+n != s3.size())
		return false;
	vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (i == 0)
			{
				if (j == 0)
					dp[i][j] = true;
				else
				{
					if (s3[j-1] == s2[j-1])
						dp[i][j] = dp[i][j-1];
					else
						dp[i][j] = false;
				}
			}
			else
			{
				if (j == 0)
				{
					if (s3[i-1] == s1[i-1])
						dp[i][j] = dp[i-1][j];
					else
						dp[i][j] = false;
				}
				else
				{
					if (s3[i+j-1] == s1[i-1])
						dp[i][j] = dp[i][j] || dp[i-1][j];
					if (s3[i+j-1] == s2[j-1])
						dp[i][j] = dp[i][j] || dp[i][j-1];
				}
			}
		}
	}

	return dp[m][n];
}

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadbbbaccc";

	cout << isInterleave(s1,s2,s3) << endl;
	cout << isInterleave(s1,s2,s4) << endl;

	return 0;
}
