/*
 * 60 Permutation Sequence
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.""""""""""""
 * */

#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

//构造一个每位是n,..,1进位的数，如1001，就表示从原序列1234，依次取第一个，第0个，第0个，第1个

vector<int> getKNum(int n,int k)
{
    vector<int> a(n, 0);
    if (k == 1)
        return a;

    vector<int> maxc(n, 1); // maxc[i]表示从i位到最后一位可表示的数的个数
    for (int i = n -2; i >= 0; --i) {
        maxc[i] = maxc[i+1] * (n - i);
    }

    k -= 1;
    for (int i = 0; i < n - 1 && k > 0; ++i) {
        if (k <  maxc[i + 1])
            continue;
        a[i] = k / maxc[i+1];
        k = k % maxc[i+1];
    }

    return a;
}

string getPermutation(int n, int k)
{
    vector<int> seq(n, 0);
    iota(seq.begin(), seq.end(), 1);

    vector<int> id = getKNum(n, k);
    string ret;
    for (int i = 0; i < n; ++i) {
        ret.push_back(seq[id[i]] + '0');
        seq.erase(seq.begin() + id[i]);
    }

    return ret;
}

int main()
{
    for (int i = 0; i < 24; ++i) {
        vector<int> ret = getKNum(5, i +1);
        for (int j = 0; j < ret.size(); ++j)
            cout << ret[j] << ",";
        cout <<endl;
        cout << getPermutation(5, i+1) << endl;
    }

    cout << getPermutation(5, 120) << endl;

}
