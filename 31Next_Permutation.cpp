// TC: O(N) for searching the element which has element(s) greater than it in it's right hand side + O(logN) for
// finding the LUB of that element + O(N) for reversing the right side of that element.
// So, TC = N + logN + N = O(N).

// SC: O(1)

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
            int low = i + 1, high = nums.size() - 1, mid = -1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(nums[mid] > nums[i]) {
                    lubIdx = mid;
                    low = mid + 1;
                } else if(nums[mid] <= nums[i]) {
                    high = mid - 1;
                }
            }

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