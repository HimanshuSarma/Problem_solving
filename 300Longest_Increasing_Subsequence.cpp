#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size, 1);

    int max = 1;

    int val = 1;

    for(int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[i] + 1;
                val = dp[i];
            } 
        }

        if (max < val) max = val;
    }  

    return max;     
}

int main () {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    lengthOfLIS(nums);
}