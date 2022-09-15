#include <bits/stdc++.h>

using namespace std;

void merge_sort_merge(vector<vector<int>>& arr, int low, int mid, int high) {
    int lowTemp = low, midTemp = mid+1, i = 0;
    vector<vector<int>> tempArr(high - low + 1);
    vector<int> temp(2);
    while(lowTemp <= mid && midTemp <= high) {
        if(arr[lowTemp][0] <= arr[midTemp][0]) {
            temp[0] = arr[lowTemp][0];
            temp[1] = arr[lowTemp][1];
            tempArr[i] = temp;
            lowTemp++;
        } else {
            temp[0] = arr[midTemp][0];
            temp[1] = arr[midTemp][1];
            tempArr[i] = temp;
            midTemp++;
        }

        i++;
    }

    if(lowTemp <= mid) {
        while(lowTemp <= mid) {
            temp[0] = arr[lowTemp][0];
            temp[1] = arr[lowTemp][1];
            tempArr[i] = temp;
            lowTemp++;
            i++;
        }
    } else if(midTemp <= high) {
        while(midTemp <= mid) {
            temp[0] = arr[midTemp][0];
            temp[1] = arr[midTemp][1];
            tempArr[i] = temp;
            midTemp++;
            i++;
        }
    }

    for(int j = 0; j < (high - low + 1); j++) {
        arr[low + j] = tempArr[j];
    }
}

void merge_sort(vector<vector<int>>& arr, int low, int high) {
    if(low >= high) return;
    else {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge_sort_merge(arr, low, mid, high);
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 1) return intervals;
    merge_sort(intervals, 0, intervals.size()-1);
    vector<vector<int>> ans;
    vector<int>temp(2);
    int i = 1;
    while(i < intervals.size()) {
        if(ans.size() == 0 && (intervals[i][0] <= intervals[i-1][1]) || ans.size() > 0 && 
        (intervals[i][0] <= ans[ans.size()-1][1])) {
            if(ans.size() == 0 && (intervals[i][1] <= intervals[i-1][1]) || 
            ans.size() > 0 && intervals[i][1] <= ans[ans.size()-1][1]) {
                if(ans.size() == 0) {
                    temp = {intervals[i-1][0], intervals[i-1][1]};
                    ans.push_back(temp);
                }
            } else {
                if(ans.size() == 0) {
                    temp = {intervals[i-1][0], intervals[i][1]};
                    ans.push_back(temp);
                } else {
                    if(intervals[i][1] > ans[ans.size()-1][1])
                        ans[ans.size()-1][1] = intervals[i][1];
                }
                    
            }
        } else {
            if(ans.size() == 0) {
                temp = {intervals[i-1][0], intervals[i-1][1]};
                ans.push_back(temp);
                
            }

            temp = {intervals[i][0], intervals[i][1]};
            ans.push_back(temp);
        }

        i += 1;
    }

    return ans;
}

int main () {
    int size;
    cin>>size; 
    vector<vector<int>> intervals(size);

    for(int i = 0; i < size; i++) {
        cout<<endl<<"Enter "<<i<<" th interval"<<endl;
        vector<int> temp(2);
        cin>>temp[0]>>temp[1];
        intervals[i] = temp;
    }

    vector<vector<int>> ans = merge(intervals);
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }

}