/*
 * =====================================================================================
 *
 *       Filename:  WordLadder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月14日 21时53分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
    if (beginWord == endWord)
        return 0;
    unordered_map<string, int> step;
    step[beginWord] = 1;
    queue<string> q;
    q.push(beginWord);
    while(!q.empty())
    {
        string word = q.front();
        int curstep = step[word] + 1;
        q.pop();
        for (int i = 0; i <= word.length(); ++i)
        {
            for(char c = 'a'; c != 'z'; ++c)
            {
                char tmp = word[i];
                word[i] = c;
                if (word == endWord)
                    return curstep;
                if (wordDict.find(word) != wordDict.end() && step.find(word) == step.end())
                {
                    q.push(word);
                    step.insert(make_pair(word, curstep));
                }
                word[i] = tmp;
            }
        }
    }
    // 无法转换到最终的单词    
    return 0;
}

int main()
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> wordDict = {"hot","dot","dog","lot","log"};

    cout << ladderLength(start,end,wordDict)<< endl;    

    return 0;
}
