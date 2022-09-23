#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(int n) {
    if(n % 2 == 0) cout<<n-1<<endl;
    else cout<<(n/2)*2<<endl;
}

int main() {
    int n;
    cin>>n;
    solve(n);
}