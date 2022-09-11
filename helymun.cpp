#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> arr, int size, int currentLevel, stack<vector<int>>& ans) {
  if(currentLevel >= arr.size()) return;
  else if(currentLevel == 0) {
    ans.push(arr);
    solve(arr, size-1, currentLevel+1, ans);
  } else {
    vector<int> currentLvlAns(size);
    for(int i = 0; i < size; i++) {
        currentLvlAns[i] = ans.top()[i] + ans.top()[i+1];
    }

    ans.push(currentLvlAns);
    solve(arr, size-1, currentLevel+1, ans);
  }
}

int main () {
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    stack<vector<int>> ans;
    solve(arr, size, 0, ans);
    int ansSize = ans.size();
    for(int i = 0; i < ansSize; i++) {
        for(int j = 0; j < ans.top().size(); j++) {
            cout<<ans.top()[j]<<" ";
        }

        ans.pop();
        cout<<endl;
    }
}