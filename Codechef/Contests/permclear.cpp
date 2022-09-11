#include <bits/stdc++.h>

using namespace std;

void solve(int N, int K, int* arr, int* b) {
    unordered_map<int, bool> bMap;
    for(int i = 0; i < K; i++) {
        bMap.insert({b[i], true});
    }

    for(int i = 0; i < N; i++) {
        if(bMap.find(arr[i]) == bMap.end()) {
            cout<<arr[i]<<" ";
        }
    }

    cout<<endl;
}

int main() {
    int T, N, K;
    int* arr = nullptr;
    int* b = nullptr;
    cin>>T;
    while(T >= 1) {
        cin>>N;
        arr = new int[N];
        for(int i = 0; i < N; i++) {
            cin>>arr[i];
        }

        cin>>K;
        b = new int[K];
        for(int i = 0; i < K; i++) {
            cin>>b[i];
        }

        solve(N, K, arr, b);
        T--;
    }
}