#include <bits/stdc++.h>

using namespace std;

int minOfTwo(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int minPathSum(vector<vector<int>>& grid) {
    int* dp = new int[grid.size() * grid[0].size()];

    for (int i = grid.size() - 1; i >= 0; i--) {
        for (int j = grid[0].size() - 1; j >= 0; j--) {
            if (i == grid.size() - 1) {
                if (j == grid[0].size() - 1) {
                    *(dp + i * (grid[0].size()) + j) = grid[i][j];
                } else {
                    *(dp + i * (grid[0].size()) + j) = grid[i][j] + *(dp + i * (grid[0].size()) + (j + 1));
                }
            } else if (j == grid[0].size() - 1 && i != grid.size() - 1) {
                *(dp + i * (grid[0].size()) + j) = grid[i][j] + *(dp + (i + 1) * (grid[0].size()) + j);
            } else {
                *(dp + i * (grid[0].size()) + j) = grid[i][j] + minOfTwo(*(dp + (i + 1) * (grid[0].size()) + j), 
                    *(dp + i * (grid[0].size()) + (j + 1)));
            }
        }
    } 

    return *(dp + 0 * (grid[0].size()) + 0);
}

int main () {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    minPathSum(grid);
}

