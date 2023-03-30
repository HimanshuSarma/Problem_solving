#include <bits/stdc++.h>

using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;

    int totalNodesOnLeft = 0;
    int totalNodesOnRight = 0;

    int totalChoices = 0;

    for (int i = 1; i <= n; i++) {
        totalChoices = 0;
        for (int j = 1; j <= i; j++) {
            totalNodesOnLeft = j-1;
            totalNodesOnRight = i-totalNodesOnLeft-1;
            totalChoices += dp[totalNodesOnLeft] * dp[totalNodesOnRight];
        }

        dp[i] = totalChoices;
    }  

    return dp[n];     
}

int main () {
    numTrees(5);
}