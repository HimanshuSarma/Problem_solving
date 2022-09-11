#include <bits/stdc++.h>

#define ll long long 
#define lld long double

using namespace std;

void solve(lld a, lld x, lld b, lld y) {
    lld speedAlice = a / x, speedBob = b / y;
    if(speedAlice > speedBob) cout<<"alice"<<endl;
    else if(speedAlice < speedBob) cout<<"bob"<<endl;
    else cout<<"equal"<<endl; 
}

int main() {
    ll T; 
    lld a, x, b, y;
    cin>>T;
    while(T >= 1) {
        cin>>a>>x>>b>>y;
        solve(a, x, b, y);
        T--;
    }
}