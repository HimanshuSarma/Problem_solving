// TC: (4^0 + 4^1 + 4^2 + .... + 4^(n-1))(M*N) 
// SC: (4^0 + 4^1 + 4^2 + .... + 4^(n-1))

// Refer to this video for more explanation: https://www.youtube.com/watch?v=hPyR1un7_hw&t=1s

#include <bits/stdc++.h>

using namespace std;

bool existsHelper(vector<vector<char>>& board, int i, int j, string word, int currentWordChar = 0) {
    if (currentWordChar == word.size()) return true;
    
    if (i >= board.size() || j >= board[0].size() || board[i][j] == '#') return false;
    char currentBoardChar = board[i][j];
    char currentWordCharacter = word[currentWordChar];

    board[i][j] = '#';

    if (currentBoardChar == currentWordCharacter) {
        if (existsHelper(board, i, j + 1, word, currentWordChar + 1)) {
            return true;
        };

        if (existsHelper(board, i + 1, j, word, currentWordChar + 1)) {
            return true;
        };

        if (existsHelper(board, i, j - 1, word, currentWordChar + 1)) {
            return true;
        };

        if (existsHelper(board, i - 1, j, word, currentWordChar + 1)) {
            return true;
        };
    }

    board[i][j] = currentBoardChar;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                if (existsHelper(board, i, j, word, 0)) {
                    return true;
                }
            };
        }
    }

    return false;
}

int main () {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<exist(board, "ABCCED");
}