#include <bits/stdc++.h>

using namespace std;

void solve(int X, int Y) {
    if(X < Y) cout<<"REPAIR"<<endl;
    else if(X > Y) cout<<"NEW PHONE"<<endl;
    else cout<<"ANY"<<endl;
}

int main() {
    int T, X, Y;
    cin>>T;
    while(T >= 1) {
        cin>>X>>Y;
        solve(X, Y);
        T--;
    }
}