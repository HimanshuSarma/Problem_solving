#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll w, ll x, ll y, ll z) {
    for(ll i = 0; i < z; i++) {
        w += x;
        w -= y;
    }

    cout<<w<<endl;
}

int main() {
    ll T, w, x, y, z;
    cin>>T;
    while(T >= 1) {
        cin>>w>>x>>y>>z;

        solve(w, x, y, z);
        T--;
    }
}