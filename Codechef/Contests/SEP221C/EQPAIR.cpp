#include <bits/stdc++.h>

#define ll long long 
#define lld long double

using namespace std;

map<pair<int, int>, bool> pairMap;


void solve(ll size, int* arr) {
    ll ans = 0;
    ll smaller, lcm;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(pairMap.count({arr[i], arr[j]}) == 0 && pairMap.count({arr[j], arr[i]}) == 0) {
                if(arr[i] <= arr[j]) smaller = arr[i];
                else smaller = arr[j];

                for(ll k = smaller; k >= 1; k--) {
                    if(arr[i] % k == 0 && arr[j] % k == 0) {
                        lcm = abs(arr[i] * arr[j]) / k;
                        if(lcm == k) ans++;
                        break;
                    }
                }

                pairMap.insert({{arr[i], arr[j]}, true});
            } 
        }
    }

    cout<<ans<<endl;
}

int main() {
    ll T; 
    ll n;
    int* arr = nullptr;
    cin>>T;
    while(T >= 1) {
        cin>>n;
        arr = new int[n];
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        solve(n, arr);
        T--;
    }
}