#include <bits/stdc++.h>

#define ll long long int
#define lld long double

using namespace std;

ll minIV = INT_MAX, maxIV = INT_MIN;


// Divide and conquer approach...
vector<ll> merge(ll* arr, ll low, ll mid, ll high, vector<ll> minmaxleft, vector<ll> minmaxright) {
    vector<ll> mergedminmax(2);
    if(minmaxleft[0] <= minmaxright[0]) mergedminmax[0] = minmaxleft[0];
    else mergedminmax[0] = minmaxright[0];

    if(minmaxleft[1] >= minmaxright[1]) mergedminmax[1] = minmaxleft[1];
    else mergedminmax[1] = minmaxright[1];

    if(mergedminmax[0] * mergedminmax[1] <= minIV) minIV = mergedminmax[0] * mergedminmax[1];
    if(mergedminmax[0] * mergedminmax[1] >= maxIV) maxIV = mergedminmax[0] * mergedminmax[1];

    return mergedminmax;
}

vector<ll> solveRec(ll* arr, ll low, ll high) {
    if(low == high) {
        vector<ll> minmax(2);
        minmax[0] = arr[low]; minmax[1] = arr[low];
        if(minmax[0]*minmax[1] <= minIV) minIV = minmax[0]*minmax[1];
        if(minmax[0]*minmax[1] >= maxIV) maxIV = minmax[0]*minmax[1];
        return minmax;
    } else {
        ll mid = (low + high) / 2;
        vector<ll> minmaxleft = solveRec(arr, low, mid);
        vector<ll> minmaxright = solveRec(arr, mid+1, high);
        return merge(arr, low, mid, high, minmaxleft, minmaxright);
    }
}

void solve(ll size, ll* arr) {
    minIV = arr[0]*arr[0]; maxIV = arr[0]*arr[0];
    solveRec(arr, 0, size-1);
    cout<<minIV<<" "<<maxIV<<endl;
}
// Divide and conquer approach...

void solveLinear(ll size, ll* arr) {
    ll min = arr[0], max = arr[0];
    for(ll i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
        else if(arr[i] > max) max = arr[i];
    }

    if(min >= 0 && max >= 0) cout<<min*min<<" "<<max*max<<endl;
    else if(min < 0 && max >= 0) {
        if(min*min > max*max) {
            cout<<min*max<<" "<<min*min<<endl;
        } else cout<<min*max<<" "<<max*max<<endl;
    }
    else if(min < 0 && max < 0) {
        cout<<max*max<<" "<<min*min<<endl;
    }
}


int main() {
    ll T; 
    ll n;
    ll* arr = nullptr;
    cin>>T;
    while(T >= 1) {
        cin>>n;
        arr = new ll[n];
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        solveLinear(n, arr);
        T--;
    }
}