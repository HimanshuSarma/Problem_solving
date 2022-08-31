// Approach 1:
// TC: 1 + 2 + 3 + ... + N = O(N^2)
// SC: O(N) because we will have N recursive calls.

// Approach 2:
// TC: 1 + 2 + 3 + ... + N = O(N^2)
// SC: O(1) because we are not using recursion.


#include <bits/stdc++.h>

using namespace std;

// Approach 1:

void generateHelperApp1(int numRows, int currentRow, vector<vector<int>>& answer) {
    vector<int> currentRowAns(currentRow);
    if(currentRow == 1) {
        currentRowAns[0] = 1;
        answer[currentRow-1] = currentRowAns;
        generateHelperApp1(numRows, currentRow + 1, answer);
        return;
    }

    if(currentRow > numRows) return;

    for(int i = 0; i < ceil(currentRow / 2.0); i++) {
        if(i == 0) {
            currentRowAns[i] = 1;
            currentRowAns[currentRow - 1] = 1;
        }
        else {
            currentRowAns[i] = answer[currentRow-2][i-1] + answer[currentRow-2][i];
            currentRowAns[currentRow - 1 - i] = answer[currentRow-2][i-1] + answer[currentRow-2][i];
        }
    }

    answer[currentRow-1] = currentRowAns;
    generateHelperApp1(numRows, currentRow + 1, answer);
}

vector<vector<int>> generateApp1(int numRows) {
    vector<vector<int>> answer(numRows);
    generateHelperApp1(numRows, 1, answer);
    return answer;
}

// Approach 1

// Approach 2:

vector<vector<int>> generateApp1(int numRows) {
    vector<vector<int>> answer(numRows);
    
    for(int i = 0; i < numRows; i++) {
        vector<int> currentRowAns(i + 1);
        for(int j = 0; j < ceil((i + 1) / 2.0); j++) {
            if(j == 0) {
                currentRowAns[j] = 1;
                currentRowAns[i] = 1;
            } else {
                currentRowAns[j] = answer[i - 1][j - 1] + answer[i - 1][j];
                currentRowAns[i - j] = answer[i - 1][j - 1] + answer[i - 1][j];
            }
        }

        answer[i] = currentRowAns;
    }


    return answer;
}

int main () {
    generateApp1(5);
}