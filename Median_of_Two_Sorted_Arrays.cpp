#include <bits/stdc++.h>

using namespace std;


// Approach 1...
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     double ans;
//     double firstmedian, secondmedian;
//     if(!nums1.size()) {
//         if(nums2.size() % 2 == 0) {
//             firstmedian = nums2[(nums2.size() / 2) - 1];
//             secondmedian = nums2[(nums2.size() / 2)];
//             ans = (firstmedian + secondmedian) / 2;
//         } else {
//             firstmedian = nums2[nums2.size() / 2];
//             ans = firstmedian;
//         }

//         return ans;
//     } else if(!nums2.size()) {
//         if(nums1.size() % 2 == 0) {
//             firstmedian = nums1[(nums1.size() / 2) - 1];
//             secondmedian = nums1[nums1.size() / 2];
//             ans = (firstmedian + secondmedian) / 2;
//         } else {
//             firstmedian = nums1[nums1.size() / 2];
//             ans = firstmedian;
//         }

//         return ans;
//     }
    
//     int low1 = 0, high1 = nums1.size()-1, low2 = 0, high2 = nums2.size()-1;
//     int mid1, mid2;
//     int idx1stmedian = -1, idx2ndmedian = -1;
//     bool is1stmedianFound = false, is2ndmedianFound = false;
//     if((nums1.size() + nums2.size()) % 2 == 0) {
//         idx1stmedian = ((nums1.size() + nums2.size()) / 2) - 1;
//         idx2ndmedian = idx1stmedian + 1;
//     } else {
//         idx1stmedian = ((nums1.size() + nums2.size()) / 2);
//         idx2ndmedian = -1;
//     }

//     if(!is1stmedianFound) {
//         while(low1 <= high1) {
//             mid1 = (low1+high1) / 2;
//             if((!is1stmedianFound && mid1 > idx1stmedian) || (is1stmedianFound && !idx2ndmedian && mid1 > idx2ndmedian)) {
//                 high1 = mid1 - 1;
//             } else {
//                 int potentialAnsIdx = -1;
//                 low2 = 0, high2 = nums2.size() - 1;
//                 while(low2 <= high2) {
//                     mid2 = (low2 + high2) / 2;
//                     if(nums2[mid2] >= nums1[mid1]) {
//                         potentialAnsIdx = mid2;
//                         high2 = mid2 - 1;
//                     } else {
//                         low2 = mid2 + 1;
//                     }
//                 }

//                 if(potentialAnsIdx >= 0) {
//                     if((!is1stmedianFound && potentialAnsIdx + mid1 == idx1stmedian)){
//                         firstmedian = nums1[mid1];
//                         low1 = mid1+1;
//                         is1stmedianFound = true;
//                         break;
//                     } else if((!is1stmedianFound && potentialAnsIdx + mid1 < idx1stmedian)) {
//                         low1 = mid1+1;
//                     } else {
//                         high1 = mid1-1;
//                     }
//                 } else {
//                     if(potentialAnsIdx < 0) {
//                         if((!is1stmedianFound && nums2.size() + mid1 == idx1stmedian)) {
//                             firstmedian = nums1[mid1];
//                             low1 = mid1+1;
//                             is1stmedianFound = true;
//                             break;
//                         } else if((!is1stmedianFound && nums2.size() + mid1 < idx1stmedian)){
//                             low1 = mid1+1;
//                         } else {
//                             high1 = mid1-1;
//                         }
//                     } else {
//                         if((!is1stmedianFound && mid1 + potentialAnsIdx == idx1stmedian)) {
//                             firstmedian = nums1[mid1];
//                             low1 = mid1+1;
//                             is1stmedianFound = true;
//                             break;
//                         } else if((!is1stmedianFound && mid1 + potentialAnsIdx < idx1stmedian)) {
//                             low1 = mid1+1;
//                         } else {
//                             high1 = mid1-1;
//                         }
//                     }
//                 }
                
//             }
//         }
//     }   
    

//     low2 = 0, high2 = nums2.size()-1;
//     if(!is1stmedianFound) {
//         while(low2 <= high2) {
//             mid2 = (low2+high2) / 2;
//             if((!is1stmedianFound && mid2 > idx1stmedian) || (is1stmedianFound && !idx2ndmedian && mid2 > idx2ndmedian)) {
//                 high2 = mid2 - 1;
//             } else {
//                 int potentialAnsIdx = -1;
//                 low1 = 0, high1 = nums1.size() - 1;
//                 while(low1 <= high1) {
//                     mid1 = (low1 + high1) / 2;
//                     if(nums1[mid1] > nums2[mid2]) {
//                         potentialAnsIdx = mid1;
//                         high1 = mid1 - 1;
//                     } else {
//                         low1 = mid1 + 1;
//                     }
//                 }

//                 if(potentialAnsIdx < 0) {
//                     if((!is1stmedianFound && nums1.size() + mid2 == idx1stmedian)) {
//                         is1stmedianFound = true;
//                         firstmedian = nums2[mid2];
//                         low2 = mid2+1;
//                         break;
//                     } else if((!is1stmedianFound && nums1.size() + mid2 < idx1stmedian)) {
//                         low2 = mid2+1;
//                     } else {
//                         high2 = mid2-1;
//                     }
//                 } else {
//                     if((!is1stmedianFound && mid2 + potentialAnsIdx == idx1stmedian)) {
//                         firstmedian = nums2[mid2];
//                         is1stmedianFound = true;
//                         low2 = mid2+1;
//                         break;
//                     } else if((!is1stmedianFound && mid2 + potentialAnsIdx < idx1stmedian)) {
//                         low2 = mid2+1;
//                     } else {
//                         high2 = mid2-1;
//                     }
//                 }
//             }
//         }
//     } 
    
//     if(is1stmedianFound && idx2ndmedian >= 0) {
//         low1 = 0, high1 = nums1.size()-1;
//         while(low1 <= high1) {
//             mid1 = (low1+high1) / 2;
//             if(mid1 > idx2ndmedian) {
//                 high1 = mid1 - 1;
//             } else {
//                 int potentialAnsIdx = -1;
//                 low2 = 0, high2 = nums2.size() - 1;
//                 while(low2 <= high2) {
//                     mid2 = (low2 + high2) / 2;
//                     if(nums2[mid2] >= nums1[mid1]) {
//                         potentialAnsIdx = mid2;
//                         high2 = mid2 - 1;
//                     } else {
//                         low2 = mid2 + 1;
//                     }
//                 }


//                 if(potentialAnsIdx < 0) {
//                     if(nums2.size() + mid1 == idx2ndmedian) {
//                         secondmedian = nums1[mid1];
//                         break;
//                     } else if(nums2.size() + mid1 < idx2ndmedian) {
//                         low1 = mid1+1;
//                     } else {
//                         high1 = mid1-1;
//                     }
//                 } else {
//                     if(mid1 + potentialAnsIdx == idx2ndmedian) {
//                         secondmedian = nums1[mid1];
//                         break;
//                     } else if(mid1 + potentialAnsIdx < idx2ndmedian) {
//                         low1 = mid1+1;
//                     } else {
//                         high1 = mid1-1;
//                     }
//                 }
//             }
//         }
//     }

//     if(is1stmedianFound && idx2ndmedian >= 0) {
//         low2 = 0, high2 = nums2.size()-1;
//         while(low2 <= high2) {
//             mid2 = (low2+high2) / 2;
//             if(mid2 > idx2ndmedian) {
//                 high2 = mid2 - 1;
//             } else {
//                 int potentialAnsIdx = -1;
//                 low1 = 0, high1 = nums1.size() - 1;
//                 while(low1 <= high1) {
//                     mid1 = (low1 + high1) / 2;
//                     if(nums1[mid1] > nums2[mid2]) {
//                         potentialAnsIdx = mid1;
//                         high1 = mid1 - 1;
//                     } else {
//                         low1 = mid1 + 1;
//                     }
//                 }

//                 if(potentialAnsIdx < 0) {
//                     if(nums1.size() + mid2 == idx2ndmedian) {
//                         secondmedian = nums2[mid2];
//                         low2 = mid2+1;
//                         is2ndmedianFound = true;
//                         break;
//                     } else if(nums1.size() + mid2 < idx2ndmedian) {
//                         low2 = mid2 + 1;
//                     } else {
//                         high2 = mid2 - 1;
//                     }
//                 } else {
//                     if(mid2 + potentialAnsIdx == idx2ndmedian) {
//                         secondmedian = nums2[mid2];
//                         low2 = mid2+1;
//                         is2ndmedianFound = true;
//                         break;
//                     } else if(mid2 + potentialAnsIdx < idx2ndmedian) {
//                         low2 = mid2+1;
//                     } else {
//                         high2 = mid2-1;
//                     }
//                 }
//             }
//         }


//     }

//     if(idx1stmedian >= 0 && idx2ndmedian >= 0) ans = (firstmedian + secondmedian) / 2;
//     else ans = firstmedian;
//     return ans;
// }

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     int l1, l2, r1, r2;
//     int n = nums1.size(), m = nums2.size();

//     l1 = (n / 2);
//     l2 = (m / 2) - 1;
// }
// Approach 1...


int maxOfTwo(int a, int b) {
    if(a >= b) return a;
    else return b;  
}

int minOfTwo(int a, int b) {
    if(a <= b) return a;
    else return b;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ans;
    if(nums1.size() == 1 && nums2.size() == 1) {
        ans = (nums1[0] + nums2[0]) / 2.0;
        return ans;
    }

    if(nums1.size() == 0) {
        // Write what happens here..
        if(nums2.size() % 2 == 0) {
            ans = ((nums2[(nums2.size()/2) - 1] + nums2[(nums2.size()/2)]))/2.0;
        } else {
            ans = nums2[nums2.size()/2];
        }

        return ans;
    } 

    if(nums2.size() == 0) {
        // Write what happens here..
        if(nums1.size() % 2 == 0) {
            ans = ((nums1[(nums1.size()/2) - 1] + nums1[(nums1.size()/2)]))/2.0;
        } else {
            ans = nums1[nums1.size()/2];
        }

        return ans;
    }

    int low1 = 0, low2 = 0, high1, high2, mid1, mid2, l1, l2,  r1, r2, median1 = INT_MIN, median2 = INT_MIN;
    int n = nums1.size(), m = nums2.size();
    high1 = n-1, high2 = m-1; 

    mid1 = (low1+high1) / 2;
    l1 = mid1;
    r1 = l1+1;

    l2 = (n+m) % 2 != 0 ? ((n+m)/2 - (l1+1)) : ((n+m)/2 - (l1+1) - 1);
    r2 = l2+1;

    high1 = l1;

    while(low1 <= high1) {
        mid1 = (low1 + high1) / 2;
        if(r1 <= n-1 && l2 >= 0 && l1>= 0 && r2 <= m-1 && 
        nums1[l1] <= nums2[r2] && nums2[l2] <= nums1[r1]) break;
        else if(r1 <= n-1 && l2 >= 0 && (r2 >= m || l1 < 0) && nums2[l2] <= nums1[r1]) break;
        else if(r2 <= m-1 && l1 >= 0 && (l2 < 0 || r1 >= n) && nums1[l1] <= nums2[r2]) break;
        else if(r2 <= m-1 && l1 >= 0 && nums1[l1] > nums2[r2]) {
            high1 = mid1-1;
            l2 += l1 - high1;
            r2 = l2+1;
            l1 = high1;
            r1 = l1+1;
        } else if(r1 <= n-1 && l2 >= 0 && nums2[l2] > nums1[r1]) {
            low1 = mid1+1;
            l2 -= (low1 - l1);
            r2 = l2+1;
            l1 = low1;
            r1 = l1+1;
        } else if(r1 >= n && r2 >= m) break;  
    }

    if((n+m) % 2 == 0) {
        if(l1 >= 0 && l2 >= 0) {
            median1 = maxOfTwo(nums1[l1], nums2[l2]);
        } else if(l1 < 0) {
            median1 = nums2[l2];
        } else median1 = nums1[l1];

        if(r1 >= 0 && r1 <= n-1 && r2 >= 0 && r2 <= m-1) {
            median2 = minOfTwo(nums1[r1], nums2[r2]);
        } else if(r1 >= 0 && r1 <= n-1) {
            median2 = nums1[r1];
        } else median2 = nums2[r2];
    } else {
        if(l1 >= 0 && l2 >= 0) {
            median1 = maxOfTwo(nums1[l1], nums2[l2]);
        } else if(l1 < 0) {
            median1 = nums2[l2];
        } else median1 = nums1[l1];
    }

    if(median2 == INT_MIN) {
        ans = median1;
    } else ans = (median1 + median2) / 2.0;

    return ans;
}


int main () {
    vector<int> nums1 = {2, 3, 4};
    vector<int> nums2 = {1};
    cout<<findMedianSortedArrays(nums1, nums2);
}