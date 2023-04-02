#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsetsWithDupHelper(vector<int>& nums, int currentEl = 0) {
    
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    subsetsWithDupHelper(nums);
}

int main () {
    vector<int> nums = {1, 2, 3};
    // subsets(nums);
}