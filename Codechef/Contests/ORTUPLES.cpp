#include <bits/stdc++.h>

using namespace std;

void solve(unsigned long long int p, unsigned long long int q, unsigned long long int r) {
    unsigned long long int max = -1;
    if(p >= q && p >= r) max = p;
    else if(q >= p && q >= r) max = q;
    else max = r;

    int totalShifts = floor(log2(max)) + 1;
    int total1s = -1;
    int rcurbit, qcurbit, pcurbit;
    unsigned long long  int ans = 1;
    for(int i = 0; i < totalShifts; i++) {
        rcurbit = 1 & r;
        qcurbit = 1 & q;
        pcurbit = 1 & p;
        total1s = rcurbit + qcurbit + pcurbit;
        if(total1s == 1) {
            cout<<0<<endl;
            return;
        }
        else if(total1s == 3) ans *= 4;  

        p = p >> 1;
        q = q >> 1;
        r = r >> 1;
    }

    cout<<ans<<endl;
}

int main() {
    unsigned long long int T, p, q, r;
    cin>>T;
    while(T >= 1) {
        cin>>p>>q>>r;

        solve(p, q, r);
        T--;
    }
}