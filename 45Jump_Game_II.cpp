#include <bits/stdc++.h>

using namespace std;

class cacheEl {
public:
    int ans = -1;
    int ansIdx = -1;
};

// int jump(vector<int>& nums) {
//     int size = nums.size();
//     if ((nums[0] == (size - 1) && size > 1)) return 1;
//     if (size == 1) return 0;

//     vector<cacheEl> cache(size);

//     int currentMin = INT_MAX;

//     for (int i = (size - 2); i >= 0; i--) {
//         if (nums[i] != 0) {
//             if (i + nums[i] >= (size - 1)) {
//                 cache[i].ans = 1;
//                 cache[i].ansIdx = i;
//             } else {

//                 currentMin = INT_MAX;
//                 for (int j = i + 1; j <= i + nums[i]; j++) {
//                     if ((cache[j].ans != -1) && ((cache[j].ans + 1) < currentMin)) currentMin = cache[j].ans + 1;
//                 }

//                 if (currentMin != INT_MAX) {
//                     cache[i].ans = currentMin;
//                     cache[i].ansIdx = i;
//                 }
//             }
//         } else {
//             cache[i].ans = -1;
//             cache[i].ansIdx = -1;
//         }
        
//     }

//     return cache[0].ans;
// }


int jump(vector<int>& nums) {
    int size = nums.size();
    if ((nums[0] == (size - 1) && size > 1)) return 1;
    if (size == 1) return 0;

    int currMax = 0;
    int currReach = 0;
    int jumps = 0;

    for (int i = 0; i < size; i++) {
        if (i + nums[i] >= size - 1) return (jumps + 1);
        
        if (i + nums[i] > currMax) {
            currMax = i + nums[i];
        }

        if (i == currReach) {
            jumps++;
            currReach = currMax;
        }
    }

    return jumps;
}



int main () {
    vector<int> nums = {1, 1, 1, 1};
    cout<<jump(nums);
}