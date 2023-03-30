// SC: O(M*N)
// TC: O(M*N)

#include <bits/stdc++.h>

using namespace std;

int minOfThree(int a, int b, int c) {
    if (a <= b) {
        if (a <= c) return a;
        else if (b <= c) return b;
        else return c;
    } else {
        if (b <= c) return b;
        else if (c <= a) return c;
        else return a;
    }
}

int minDistance(string word1, string word2) {
    int currentRowPrev = 0;
    int currentRowCurrent = word1.size() || word2.size();

    vector<int> prevRow(word2.size()+1);

    int insert = 0;
    int remove = 0;
    int replace = 0;

    for (int i = 0; i <= word1.size(); i++) {
        for (int j = 0; j <= word2.size(); j++) {
            if (i == 0) {
                prevRow[j] = j;
            } else if (j == 0) {
                currentRowPrev = i;
            } else {
                if (word1[i-1] == word2[j-1]) {
                    currentRowCurrent = prevRow[j-1];
                } else {
                    insert = currentRowPrev + 1;
                    remove = prevRow[j] + 1;
                    replace = prevRow[j-1] + 1;
                    currentRowCurrent = minOfThree(insert, remove, replace);
                }

                prevRow[j-1] = currentRowPrev;

                currentRowPrev = currentRowCurrent;
                if (j == word2.size()) {
                    prevRow[j] = currentRowCurrent;
                } 
            }
        }
    }

    return currentRowCurrent;
}

int main () {
    string word1 = "intention";
    string word2 = "execution";
    minDistance(word1, word2);
}