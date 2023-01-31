// TC: O(N)
// SC: O(1)


#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    int size = nums.size() - 1;
    int max = nums[size];

    int rm1, rm2;

    if (nums[size] < 0) {
        rm1 = -1;
        rm2 = nums[size];
    } else if (nums[size] > 0) {
        rm1 = nums[size];
        rm2 = 1;
    } else {
        rm1 = -1;
        rm2 = 1;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] == 0) {
            rm1 = -1;
            rm2 = 1;

            if (nums[i] > max) max = nums[i];
        } else {
            if (nums[i] < 0) {
                if (rm1 != -1 && rm2 != 1) {
                    int tempRM1 = rm1;
                    rm1 = nums[i] * rm2;
                    rm2 = nums[i] * tempRM1;
                } else if (rm1 != -1) {
                    rm2 = nums[i] * rm1;
                    rm1 = -1;
                } else if (rm2 != 1) {
                    rm1 = nums[i] * rm2;
                    rm2 = nums[i];
                } else {
                    rm1 = -1;
                    rm2 = nums[i];
                }
            } else {
                if (rm1 != -1 && rm2 != 1) {
                    rm1 = nums[i] * rm1;
                    rm2 = nums[i] * rm2;
                } else if (rm1 != -1) {
                    rm1 = nums[i] * rm1;
                    rm2 = 1;
                } else if (rm2 != 1) {
                    rm2 = nums[i] * rm2;
                    rm1 = nums[i];
                } else {
                    rm1 = nums[i];
                    rm2 = 1;
                }
            }

            if (rm1 != -1 && rm1 > max) max = rm1;
            if (rm2 != 1 && rm2 > max) max = rm2;
        }
    }

    cout<<"Ans: "<<max<<endl;
    return max;
}

int main () {
    vector<int> input = {-1,-1,0};
    maxProduct(input);
}   