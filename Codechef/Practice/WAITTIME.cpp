#include <bits/stdc++.h>

using namespace std;

void solve(int K, int X) {
    int totalDays = K*7;
    cout<<(totalDays - X)<<endl;
}

int main () {
    int T, K, X;
    cin>>T;
    while(T >= 1) {
        cin>>K>>X;
        solve(K, X);
        T--;
    }
}