#include <bits/stdc++.h>

using namespace std;

void reverseArr(vector<int>& nums, int low, int high) {
    int temp;
    int offset = 0;
    int totalIts = low + ((high-low)/2);
    for(int j = low; j < totalIts; j++) {
        temp = nums[j];
        nums[j] = nums[high - 1 - offset];
        nums[high - 1 - offset] = temp;
        offset++;
    }
}

void nextPermutation(vector<int>& nums) {
    int maxIdx = nums.size() - 1;
    int lubIdx;

    for(int i = nums.size() - 2; i >= 0; i--) {
        if(nums[i] < nums[maxIdx]) {
            for(int j = nums.size()-1; j >= i + 1; j--) {
                if(nums[j] > nums[i]) {
                    maxIdx = j; 
                    break;
                }
            }

            lubIdx = maxIdx;
            int temp = nums[i];
            nums[i] = nums[lubIdx];
            nums[lubIdx] = temp;
            reverseArr(nums, i+1, nums.size());
            return;
        } else if(nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    } 

    reverseArr(nums, 0, nums.size());   
}

int main () {
    vector<int> nums = {1, 3, 2};
    nextPermutation(nums);
}