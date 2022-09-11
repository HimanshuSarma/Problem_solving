#include <bits/stdc++.h>

using namespace std;

void solve(int x, int y) {
    int a, b, c;
    b = y;
    for(int i = -1000; i <= 1000; i++) {
        c = 3 * x - b - i;
        if(c >= -1000 && c <= 1000) {
            cout<<i<<" "<<b<<" "<<c<<endl;
            return;
        }
    }
}

int main() {
    int T, x, y;
    cin>>T;
    while(T >= 1) {
        cin>>x>>y;

        solve(x, y);
        T--;
    }
}