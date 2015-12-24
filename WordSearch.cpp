/*
 * 79 Word Search
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.""
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool help(string a, int i, int j, vector<vector<char>>& board, string word)
{
    if (a == word)
        return true;
    else {
        int sz = a.size();
        int m = board.size();
        int n = board[0].size();
        if (board[i][j] != word[sz])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        a.push_back(c);
        if (a == word)
            return true;
        int di[4] = {0, -1, 0, 1};
        int dj[4] = {1, 0, -1, 0};
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if (help(a, ni, nj, board, word))
                    return true;
            }
        }

        board[i][j] = c;
            
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word)
{
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[i].size(); ++j)
            if (help("", i, j, board, word))
                return true;

    return false;
}

int main()
{
    vector<vector<char>> board ={{'A', 'B','C','E'}, {'S', 'F','C', 'S'},{'A','D','E','E'}};
    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCB") << endl;
}
