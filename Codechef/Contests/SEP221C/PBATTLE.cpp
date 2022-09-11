#include <bits/stdc++.h>

#define ll long long 
#define lld long double

using namespace std;

map<pair<int, int>, bool> pairMap;


void solve(ll size, int* gnd, int* water) {
    
}

int main() {
    ll T; 
    ll n;
    int* gnd = nullptr; int* water = nullptr;
    cin>>T;
    while(T >= 1) {
        cin>>n;
        gnd = new int[n]; 
        water = new int[n];
        for(int i = 0; i < n; i++) {
            cin>>gnd[i];
        }
        for(int i = 0; i < n; i++) {
            cin>>water[i];
        }
        solve(n, gnd, water);
        T--;
    }
}