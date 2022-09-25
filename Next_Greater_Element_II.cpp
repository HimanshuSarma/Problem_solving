// Approach 1:
// TC: Worst case: 3*N(If there exists only 1 distinct element in the entire array.)
//     Best case: (2*N + total_instances_of_the_largest element) {If there exists at least 2 distinct elements
//                in the entire array.} 
//     So, time complexity: O(N).

// SC: Worst case: N, so O(N).


#include <bits/stdc++.h>

using namespace std;

// Approach 1...
stack<int> els;

vector<int> nextGreaterElements(vector<int>& nums) {
    els.push(0);
    vector<int> ans(nums.size());
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] <= nums[els.top()]) {
            els.push(i);
        } else {
            while(!els.empty() && nums[i] > nums[els.top()]) {
                ans[els.top()] = nums[i];
                els.pop();
            }

            els.push(i);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(els.empty()) break;

        while(!els.empty() && nums[i] > nums[els.top()] && i != els.top()) {
            ans[els.top()] = nums[i];
            els.pop();
        }
    }

    if(!els.empty()) {
        while (!els.empty()) {
            ans[els.top()] = -1;
            els.pop();
        }
    }
     
    return ans;
}
// Approach 1   

int main() {
    vector<int> arr = {1, 1, 1, 1, 1};
    vector<int> ans = nextGreaterElements(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}