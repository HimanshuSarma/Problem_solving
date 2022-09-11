// Solution 1. Kadane's algorithm:
// TC: O(N)
// SC: O(1)
// Solution 1. Kadane's algorithm:

// Solution 2: Divide and conquer algorithm:
// TC: O(NlogN)
// SC: O(logN) Recursive call stack.
// Solution 2: Divide and conquer algorithm:

#include <bits/stdc++.h>

using namespace std;

// Solution 1. Kadane's algorithm Recursive...
int maxSubArrayRecHelper(vector<int>& nums, int currentEl, int max, int sumSoFar) {
    if(currentEl >= nums.size()) return max;
    else {
        if(sumSoFar < 0) {
            sumSoFar = nums[currentEl];
            if(sumSoFar > max) max = sumSoFar;
            return maxSubArrayRecHelper(nums, currentEl + 1, max, sumSoFar);
        } else {
            sumSoFar += nums[currentEl];
            if(sumSoFar > max) max = sumSoFar;
            return maxSubArrayRecHelper(nums, currentEl + 1, max, sumSoFar);
        }
    }
}

int maxSubArrayRec(vector<int>& nums) {
    return maxSubArrayRecHelper(nums, 1, nums[0], nums[0]);
}
// Solution 1. Kadane's algorithm Recursive...


// Solution 2. Kadane's algorithm Iterative...
int maxSubArrayIterative(vector<int>& nums) {
    int sumSoFar = nums[0];
    int max = sumSoFar;
    for(int i = 1; i < nums.size(); i++) {
        if(sumSoFar < 0) {
            sumSoFar = nums[i];
        } else {
            sumSoFar += nums[i];
        }

        if(sumSoFar > max) max = sumSoFar;
    }

    return max;
}
// Solution 2. Kadane's algorithm Iterative...


// Solution 3. Divide and conquer...
int findMaxAcrossSubarrays(vector<int>& nums, int low, int mid, int high) {
    int leftSubarrayLastIdx = mid, rightSubarrayFirstIdx = mid + 1, 
    leftMax = nums[leftSubarrayLastIdx], leftSumSoFar = nums[leftSubarrayLastIdx],
    rightMax = nums[rightSubarrayFirstIdx], rightSumSoFar = nums[rightSubarrayFirstIdx];
    leftSubarrayLastIdx--;
    rightSubarrayFirstIdx++;

    while (leftSubarrayLastIdx >= low && rightSubarrayFirstIdx <= high) {
        leftSumSoFar += nums[leftSubarrayLastIdx];
        rightSumSoFar += nums[rightSubarrayFirstIdx];

        if(leftSumSoFar > leftMax) leftMax = leftSumSoFar;
        if(rightSumSoFar > rightMax) rightMax = rightSumSoFar;

        leftSubarrayLastIdx--;
        rightSubarrayFirstIdx++;
    }

    if(leftSubarrayLastIdx >= low) {
        leftSumSoFar += nums[leftSubarrayLastIdx];
        if(leftSumSoFar > leftMax) leftMax = leftSumSoFar;
    }

    if(rightSubarrayFirstIdx <= high) {
        rightSumSoFar += nums[rightSubarrayFirstIdx];
        if(rightSumSoFar > rightMax) rightMax = rightSumSoFar;
    }

    return leftMax + rightMax;
}

int maxSubArrayRec(vector<int>& nums, int low, int high) {
    if(low == high) return nums[low];
    else {
        int mid = (low + high) / 2;
        int leftMax, rightMax, acrossMax;
        leftMax = maxSubArrayRec(nums, low, mid);
        rightMax = maxSubArrayRec(nums, mid + 1, high);
        acrossMax = findMaxAcrossSubarrays(nums, low, mid, high);

        if(acrossMax >= leftMax && acrossMax >= rightMax) return acrossMax;
        else {
            if(leftMax >= rightMax) return leftMax;
            else return rightMax;
        }
    }
}

int maxSubArray(vector<int>& nums) {
    return maxSubArrayRec(nums, 0, nums.size()-1);
}
// Solution 3. Divide and conquer...

int main () {
    int size;
    cin>>size;
    vector<int> nums;
    for(int i = 0; i < size; i++) {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    maxSubArray(nums);
}