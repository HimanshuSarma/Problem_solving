#include <bits/stdc++.h>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[0].size(); j++) {
            if(adj[i][j] > 0) {
                vector<int> sd = {i, j};
                minHeap.push(2);
            }
        }
    }
}

int main() {
    
}