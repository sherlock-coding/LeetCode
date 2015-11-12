/*
 * 36 Valid Sudoku
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    // rows[i][j]=true;表示第i+1行存在j+1这个数
    // cols[i][j]=true;表示第i+1列存在j+1这个数
    // blocks[i][j] = true;表示第i+1个区块存在j+1这个数
    bool rows[9][9], cols[9][9], blocks[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            rows[i][j] = false;
            cols[i][j] = false;
            blocks[i][j] = false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '1';
            if (rows[i][num] || cols[j][num] || blocks[i/3*3 + j/3][num])
                return false;
            rows[i][num] = true;
            cols[j][num] = true;
            blocks[i/3*3 + j/3][num] = true;
        }
    }

    return true;
}

int main()
{

}
