/*
 * 38 Count and Say
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.""""""
 * */

#include <iostream>
#include <string>

using namespace std;

string getNext(string s)
{
    string ret;
    char cur = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i){
        if (s[i]== cur) {
            ++cnt;
            continue;
        }
        else {
            ret += std::to_string(cnt) + cur;
            cnt = 1;
            cur = s[i];
        }
    }

    ret += std::to_string(cnt)+ cur;

    return ret;

    
}

string countAndSay(int n)
{
    string s = "1";
    for (int i = 1; i < n; ++i)
        s = getNext(s);

    return s;
}

int main()
{
    for (int i = 1; i <= 5; ++i)
        cout << countAndSay(i)  << ",";
    cout << endl;
}
