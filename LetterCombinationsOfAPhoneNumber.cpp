/*
 * 17 Letter Combinartions of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.""""""""""""""""""]""
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(string& a, int k, int len, vector<string> &ret, string & digits, vector<string> & m) 
{
    string c; // candidate
    if (k == len) // 判断是否是一个解
        ret.push_back(a);
    else {
        c = m[digits[k] - '2']; // make candidate
        for (int i = 0; i < c.size(); ++i) {
            a.push_back(c[i]); // make move
            backtrack(a, k+1, len, ret, digits, m);
            a.pop_back(); // ummake_move
        }
    }
}

vector<string> letterCombinations(string digits) 
{
    vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = digits.size();
    vector<string> ret;
    string a;

    if (len == 0)
        return ret;
    backtrack(a, 0, len, ret, digits, m);

    return ret;
}

int main()
{
    vector<string> ret = letterCombinations("23");
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << endl;
}
