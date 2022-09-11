#include <bits/stdc++.h>

#define ll long long 
#define lld long double

using namespace std;

map<ll, bool> distinctCalls;
map<ll, bool> distinctAns;
ll sum = 0;

void solve(ll n, ll k, ll currentLevel) {
    distinctCalls.insert({n, true});
    vector<ll> factors;
    ll sqrootN = sqrt(n);
    for(ll i = 1; i <= sqrootN; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            if(i != sqrootN)
                factors.push_back(n/i);
        }
    }

    for(ll i = 0; i < factors.size(); i++) {
        cout<<n*factors[i]<<" ";
        if(distinctAns.count(n*factors[i]) == 0) {
            sum += n*factors[i];
            distinctAns.insert({n*factors[i], true});
        }

        if(distinctCalls.count({n*factors[i]}) == 0) {
            if(currentLevel + 1 <= k) {
                solve(n*factors[i], k, currentLevel+1);
                distinctCalls.insert({n*factors[i], true});
            }
        }
    }
}

int main() {
    ll T; 
    ll n, k;
    cin>>T;
    while(T >= 1) {
        cin>>n>>k;
        solve(n, k, 1);
        cout<<sum<<endl;
        sum = 0;
        T--;
    }
}