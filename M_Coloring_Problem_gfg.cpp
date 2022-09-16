#include <bits/stdc++.h>

using namespace std;

int* vertices = new int[101];

bool graphColoring(bool graph[101][101], int m, int n, int currentVertex = 0) {
    if(currentVertex == 0) {
        for(int i = 0; i < 101; i++) {
            vertices[i] = -1;
        }
    }
    if(currentVertex == n-1) return true;
    else {
        int isColorUsedByAdjacent = false;
        for(int i = 0; i < m; i++) {
            isColorUsedByAdjacent = false;
            for(int j = 0; j < 101; j++) {
                if(graph[currentVertex][j] && vertices[j] == m) isColorUsedByAdjacent = true;
            }

            if(!isColorUsedByAdjacent) {
                vertices[currentVertex] = i;
                if(graphColoring(graph, m, n, currentVertex+1)) return true;
                vertices[currentVertex] = -1;
            }
        }

        return false;
    }
}  

int main () {
    
}