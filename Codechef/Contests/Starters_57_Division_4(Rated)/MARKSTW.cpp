#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(int x, int y) {
    if(x >= 2*y) cout<<"yes"<<endl;
    else if(x < 2*y) cout<<"no"<<endl;
}

int main() {
    int x, y;
    cin>>x>>y;
    solve(x, y);
}