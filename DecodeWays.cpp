#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOk(string s)
{
	if (s[0] == '0' || s[0] > '2')
		return false;
	if (s[0] == '2' && s[1] > '6')
		return false;
	return true;
}

int numDecodings(string s)
{
	const int len = s.size();
	if (len == 0 || s[0] == '0')
		return 0;
	vector<int> dp(len+1,0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i<=len; ++i)
	{
		if (s[i-1] != '0')
			dp[i] += dp[i-1];
		if (isOk(s.substr(i-2,2)))
			dp[i] += dp[i-2];
	}
	return dp[len];
}

int main()
{

	string  s;
	cin >> s;
	cout << numDecodings(s) << endl;

	return 0;
}
