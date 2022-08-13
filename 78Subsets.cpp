// Approach 1.
// TC: (2 + 2^2 + 2^3 + 2^4 + .... + 2^N) * N = O(N * 2^N).
// 2 + 2^2 + 2^3 + 2^4 + .... + 2^N = 2 * 2^N.

// SC: Stack space used is O(2^N) because we're are doing O(2^N) recursive calls.

// <<<<<<<<-------------------------------------------------------------------------------------------------------------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

// Approach 2.
// We can generate bit patterns of all the numbers from 0 to 2^N - 1, so if N = 3 generate all bit patterns 
// from 0 to 7, i.e., 000 to 111. Generate all these bit patterns will take O(2^N) time.
// So, 000 means none of the three elements will be present in the subset and 111 means all three elements 
// will be present in the subset.

// TC: O(2^N).
// SC: O(1). (Excluding the space required for the answer array).

// <<<<<<<<-------------------------------------------------------------------------------------------------------------------------------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <bits/stdc++.h>

using namespace std;

// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------>//
// Approach 1. Naive solution(Backtracking)...
vector<vector<int>> answer;
vector<int> subset;
vector<vector<int>> subsets(vector<int>& nums, int currentEl = 0) {
    if(currentEl < nums.size()) {
        subsets(nums, currentEl+1);
        subset.push_back(nums[currentEl]);
        subsets(nums, currentEl+1);
        subset.pop_back();
    } else {
        answer.push_back(subset);
        return answer;
    } 
}

int main () {
    vector<int> nums = {1, 2, 3};
    subsets(nums);
}