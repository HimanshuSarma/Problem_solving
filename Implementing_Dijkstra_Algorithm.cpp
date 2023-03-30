#include <bits/stdc++.h>

using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> ans(V, INT_MAX);
    ans[S] = 0;

    int minVal = INT_MAX;
    int minVertex = -1;

    int source = S;

    for (int i = 0; i < (V - 1); i++) {
        minVal = ans[adj[source][0][0]];
        minVertex = adj[source][0][0];

        for (int j = 0; j < adj[source].size(); j++) {
            if (ans[adj[source][j][0]] > ans[source] + adj[source][j][1]) {
                if (minVal > ans[source] + adj[source][j][1]) {
                    minVal = ans[source] + adj[source][j][1];
                    minVertex = adj[source][j][0];
                }
                ans[adj[source][j][0]] = ans[source] + adj[source][j][1];
            }
        }

        source = minVertex;
        ans[minVertex] = minVal;
    }

    return ans;
}

int main () {
    vector<vector<int>> adj[] = {{{1, 9}, {2, 1}, {3, 1}}, {{0, 9}, {3, 3}}, {{3, 2}}, {{2, 2}, {1, 3}}};
    dijkstra(4, adj, 0);
}