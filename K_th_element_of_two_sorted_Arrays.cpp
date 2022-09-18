#include <bits/stdc++.h>

using namespace std;

int maxOfTwo(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int l1low = 0, l1high, l2low = 0, l2high;
    int kHalf = k/2;
    int r1, r2;
    if(k % 2 == 0) {
        if(n >= kHalf && m >= kHalf) {
            l1high = (kHalf) - 1; l2high = (kHalf) - 1;
        } else if(n < kHalf && m >= kHalf) {
            l2high = kHalf + (kHalf - n) - 1;
            if(l2high > m - 1) return -1; 
        } else if(m < kHalf && n >= kHalf) {
            l1high = kHalf + (kHalf - m) - 1;
            if(l1high > n - 1) return -1; 
        } 
          else return -1;
    } else {
        if(n > m) {
            if(n >= kHalf && m >= kHalf) {
                l1high = (kHalf); l2high = (kHalf) - 1;
                if(l1high > n-1) return -1;
            } else if(m < kHalf && n >= kHalf) {
                l2high = m-1;
                l1high = (k - m) - 1;
                if(l1high > n - 1) return -1; 
            } else return -1;
        } else if(m > n) {
            if(n >= kHalf && m >= kHalf) {
                l1high = (kHalf) - 1; l2high = (kHalf);
                if(l2high > m-1) return -1;
            } else if(n < kHalf && m >= kHalf) {
                l1high = n-1;
                l2high = (k - n) -1;
                if(l2high > m - 1) return -1; 
            } else return -1;
        } else {
            if(n >= kHalf && m >= kHalf) {
                l1high = (kHalf); l2high = (kHalf) - 1;
                if(l1high > n-1) return -1;
            } else if(n < kHalf && m < kHalf) return -1;
        }
    }

    r1 = l1high+1; 
    r2 = l2high+1;

    if(r1 > n-1) r1 = -1;
    if(r2 > m-1) r2 = -1;

    if(arr1[0] > arr2[m-1]) {
        if(k-1 <= m-1) return arr2[k-1];
        else {
            return arr1[((k-(k-n))-1)];
        }
    }

    if(arr2[0] > arr1[n-1]) {
        if(k-1 <= n-1) return arr1[k-1];
        else {
            return arr2[((k-(k-n))-1)];
        }
    }

    if(((r2 != -1 && arr1[l1high] <= arr2[r2]) || r2 < 0) && ((r1 != -1 && arr2[l2high] <= arr1[r1]) || r1 < 0)) return maxOfTwo(arr1[l1high], arr2[l2high]);
    else if(arr1[l1high] > arr2[r2]) {
        int mid, lowTemp = l1low, highTemp = l1high;
        while(lowTemp <= highTemp) {
            mid = (lowTemp + highTemp) / 2;
            if(arr1[mid] >= arr2[r2]) {
                highTemp = mid-1;
            } else if(arr1[mid] < arr2[r2]) {
                lowTemp = mid+1;
                
            }
        } 

        mid = arr1[mid] < arr2[r2] ? mid++ : mid;
        int r1prev = r1 == -1 ? n : r1;
        r1 = mid;
        r2 += (r1prev-r1);
        l2high = r2-1; 
        l1high = r1-1;

        if(arr2[l2high] > arr1[r1]) {
            lowTemp = r1, highTemp = n-1, mid;
            while(lowTemp <= highTemp) {    
                mid = (lowTemp+highTemp)/2;
                if(arr1[mid] >= arr2[l2high]) {
                    highTemp = mid-1;
                } else {
                    lowTemp = mid+1;
                }
            }

            mid++;
            r2 -= mid-r1;
            l2high = r2-1;
            r1 = mid;
            l1high = r1-1;

        }
    } else if(arr2[l2high] > arr1[r1]) {
        int mid, lowTemp = l2low, highTemp = l2high;
        while(lowTemp <= highTemp) {
            mid = (lowTemp + highTemp) / 2;
            if(arr2[mid] >= arr1[r1]) {
                highTemp = mid-1;
            } else if(arr2[mid] < arr1[r1]) {
                lowTemp = mid+1;
            }
        } 

        mid = arr2[mid] < arr1[r1] ? mid+1 : mid;
        int r2prev = r2 == -1 ? m : r2;
        r2 = mid;
        r1 += (r2prev-r2); 
        l1high = r1-1;
        l2high = r2-1;

        if(arr1[l1high] > arr2[r2]) {
            lowTemp = r2, highTemp = m-1, mid;
            while(lowTemp <= highTemp) {    
                mid = (lowTemp+highTemp)/2;
                if(arr2[mid] >= arr1[l1high]) {
                    highTemp = mid-1;
                } else {
                    lowTemp = mid+1;
                }
            }

            mid++;
            r1 -= mid-r2;
            l1high = r1-1;
            r2 = mid;
            l2high = r2-1;
        }
    }   

    return maxOfTwo(arr1[l1high], arr2[l2high]);     
}

int main () {
    int arr1[] = {1, 2, 2 ,4, 5, 6, 9, 11, 11, 12, 20, 20, 25, 25, 26, 29, 30, 30, 31, 34, 35, 36, 36, 37, 41, 41, 43, 43, 44, 45, 45, 46, 47, 47, 47, 48, 49, 49, 50, 51, 52, 52, 52, 54, 56, 56 ,56 ,56 ,57 ,57 ,57 ,59, 60, 61, 62, 64, 65, 65, 67, 68, 68, 69, 71, 72, 73, 74, 76, 76, 81, 82, 83, 86, 87, 89, 91, 91, 91, 92, 94 ,95, 95, 96, 97, 97, 98};
    int arr2[] = {9, 53, 59, 87};

    int k = 7;
    cout<<kthElement(arr1, arr2, 85, 4, 19);

}