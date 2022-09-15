#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

void findPathHelperRec(vector<vector<int>>& maze, vector<vector<bool>>& visited, string ansSoFar, int row, int col, 
int n) {
    if(row == n-1 && col == n-1) {
        // We got an answer...
        ans.push_back(ansSoFar);
        return;
    } 

    visited[row][col] = true;
    
    if(row+1 <= n-1 && maze[row+1][col] != 0 && !visited[row+1][col]) {
        visited[row+1][col] = true;
        ansSoFar.push_back('D');
        findPathHelperRec(maze, visited, ansSoFar, row+1, col, n);
        ansSoFar.pop_back();
        visited[row+1][col] = false;
    } 
    
    if(row-1 >= 0 && maze[row-1][col] != 0 && !visited[row-1][col]) {
        visited[row-1][col] = true;
        ansSoFar.push_back('U');
        findPathHelperRec(maze, visited, ansSoFar, row-1, col, n);
        ansSoFar.pop_back();
        visited[row-1][col] = false;
    } 
    
    if(col+1 <= n-1 && maze[row][col+1] != 0 && !visited[row][col+1]) {
        visited[row][col+1] = true;
        ansSoFar.push_back('R');
        findPathHelperRec(maze, visited, ansSoFar, row, col+1, n);
        ansSoFar.pop_back();
        visited[row][col+1] = false;
    } 
    
    if(col-1 >= 0 && maze[row][col-1] != 0 && !visited[row][col-1]) {
        visited[row][col-1] = true;
        ansSoFar.push_back('L');
        findPathHelperRec(maze, visited, ansSoFar, row, col-1, n);
        ansSoFar.pop_back();
        visited[row][col-1] = false;
    }

    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &maze, int n) {
    if(maze[0][0] == 0) {
        ans.push_back("-1");
        return ans;
    }
    vector<vector<bool>> visited(maze.size(), vector<bool> (maze[0].size(), false));
    findPathHelperRec(maze, visited, "", 0, 0, n);
    return ans;
}   

int main () {
}