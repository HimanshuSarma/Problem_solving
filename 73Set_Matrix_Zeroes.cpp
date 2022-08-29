// Appproach1:
// TC: 2*N*M, i.e., O(N*M).
// SC: O(M) where M is row size.

// Appproach1:
// TC: 2*N*M, i.e., O(N*M).
// SC: O(1).

#include <bits/stdc++.h>

using namespace std;

void setZeroesApproach1(vector<vector<int>>& matrix) { 
    vector<int> cols(matrix[0].size(), 1);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                cols[j] = 0;
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            for(int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int j = 0; j < matrix[0].size(); j++) { // columns...
        if(cols[j] == 0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroesApproach2(vector<vector<int>>& matrix) {
    int row1 = 1;
    int col1 = 1;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                if(j == 0 && i != 0) {
                    col1 = 0;
                    matrix[i][0] = 0;
                } else if(i == 0 && j != 0) {
                    row1 = 0;
                    matrix[0][j] = 0;
                } else if(i == 0 && j == 0) {
                    row1 = 0;
                    col1= 0;
                } else {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for(int i = matrix.size()-1; i >= 0; i--) {
        for(int j = matrix[0].size()-1; j >= 0; j--) {
            if(i == 0 && row1 == 0) {
                matrix[i][j] = 0;
            } else if(j == 0 && col1 == 0) {
                matrix[i][j] = 0;
            } else if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main () {

}