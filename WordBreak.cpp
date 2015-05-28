// 单词划分

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string> &wordDict)
{
	int n = s.size();
	vector<int> dp(n+1, 0);
	dp[0] = 1;

	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= j; ++i)
		{
			if (wordDict.count(s.substr(i-1, j-i+1)))
			{
				dp[j] = dp[i-1];
				if (dp[j])
					break;
			}
		}
	}

	return dp[n];
}

int main()
{
	string s = "leetcode";
	unordered_set<string> wordDict = {"leet","code"};

	cout << wordBreak(s,wordDict) << endl;
}
