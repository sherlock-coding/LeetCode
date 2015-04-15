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

using namespace std;

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
    vector<vector<string> > allseq;
    unordered_map<string, string> prev; // 每个单词的前驱结点
    queue<string> q; 
    q.push(start);

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
                if (newword == end)
                {
                    vector<string> seq;
                    seq.push_back(end);
                    seq.push_back(word);
                    string tmpstr = word;
                    while(tmpstr != start)
                    {
                        seq.push_back(prev[tmpstr]);
                        tmpstr = prev[tmpstr];
                    }
                    reverse(seq.begin(),seq.end());
                    allseq.push_back(seq);
                    break;
                }
                if (dict.find(newword) != dict.end() && prev.find(newword) == prev.end())
                {
                   // cout << newword << endl;
                    q.push(newword);
                    prev.insert(make_pair(newword,word));
                }
            }
        }
    }

    return allseq;
}

int main()
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log"};

    vector<vector<string>> allseq = findLadders(start,end,dict);

    for (int i = 0; i < allseq.size(); ++i)
    {
        for (int j = 0; j < allseq[i].size(); ++j)
            cout << allseq[i][j] << " ";
        cout << endl;
    }

    return 0;
}
