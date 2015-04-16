/*
 * =====================================================================================
 *
 *       Filename:  WordLadderII.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月14日 21时50分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void DFS(string begin, string end, unordered_map<string, unordered_set<string>> &prev, vector<vector<string>> &allseq, vector<string> &seq)
{
    if (begin == end)
    {
        seq.push_back(end);
        vector<string> tmp(seq.size());
        copy(seq.begin(), seq.end(),tmp.begin());
        reverse(tmp.begin(), tmp.end());
        allseq.push_back(tmp);
        seq.pop_back();
        return ;
    }

    seq.push_back(begin);
    for (auto& word:prev[begin])
        DFS(word,end,prev,allseq,seq);
    seq.pop_back();

}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
    vector<vector<string> > allseq;
    unordered_map<string, unordered_set<string>> prev; // 每个单词的前驱结点
    unordered_map<string, int> steps;
    queue<string> q; 
    q.push(start);
    unordered_set<string> first;
    prev.insert(make_pair(start,first));
    steps.insert(make_pair(start, 1));

    if (start == end)
    {
        vector<string> seq;
        seq.push_back(start);
        allseq.push_back(seq);
        return allseq;
    }

    while(!q.empty())
    {
        string word = q.front();
        q.pop();
        for (int i = 0; i < word.length(); ++i)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                string newword = word;
                newword[i] = c;
                if (newword == word)
                    continue;
                if (dict.find(newword) != dict.end() || newword == end )
                {
                    if ( steps.find(newword) == steps.end())
                    {
                        q.push(newword);
                        steps.insert(make_pair(newword, steps[word]+1));
                        unordered_set<string> newset;
                        newset.insert(word);
                        prev.insert(make_pair(newword, newset));
                    }
                    else 
                    {
                        if (steps[word]+1 == steps[newword])
                        {
                            prev[newword].insert(word);
                        }
                    }
                }
            }
        }
    }

    // 保存序列
    vector<string> seq;
    DFS(end, start, prev, allseq, seq);

    return allseq;
}

int main()
{
    string start = "red";
    string end = "tax";
    unordered_set<string> dict = { "ted", "tex", "red", "tax", "tad", "den", "rex","pee"};

    vector<vector<string>> allseq = findLadders(start,end,dict);

      for (int i = 0; i < allseq.size(); ++i)
    {
        for (int j = 0; j < allseq[i].size(); ++j)
            cout << allseq[i][j] << " ";
        cout << endl;
    }

    return 0;
}
