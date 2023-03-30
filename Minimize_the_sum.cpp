// Problem link: https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1?page=1&company[]=Swiggy&sortBy=submissions

// TC: O(NlogN). Build heap and then 2 delete and 1 push on every iteration. In total there will be N - 1 iterations.
// SC: O(N). For the heap.

#include <bits/stdc++.h>

using namespace std;

int minimizeSum(int N, vector<int> arr) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long int runningSum = 0;
    int min1 = -1, min2 = -1;

    for (int i = 0; i < N; i++) {
        minHeap.push(arr[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        min1 = minHeap.top();
        minHeap.pop();

        min2 = minHeap.top();
        minHeap.pop();

        runningSum += min1 + min2;
        minHeap.push(min1 + min2);
    }

    return runningSum;
}

int main () {
    vector<int> arr = {1, 3, 7, 5, 6};
    minimizeSum(arr.size(), arr);
}