#include <bits/stdc++.h>

using namespace std;

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

int main() {
    vector<int> arr = {1, 1, 1, 1, 1};
    vector<int> ans = nextGreaterElements(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}