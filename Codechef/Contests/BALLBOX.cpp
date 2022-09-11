#include <bits/stdc++.h>

using namespace std;

void solve(int balls, int boxes) {
    int sumOfKBoxes = (boxes * (boxes + 1)) / 2;
    if(balls < boxes) cout<<"no"<<endl;
    else if(balls == boxes && balls == 1) cout<<"yes"<<endl;
    else if(balls == boxes && balls != 1) cout<<"no"<<endl;
    else if (balls >= sumOfKBoxes) cout<<"yes"<<endl;
    else if (balls < sumOfKBoxes) cout<<"no"<<endl;
}

int main() {
    int T, balls, boxes;
    int* arr = nullptr;
    int* b = nullptr;
    cin>>T;
    while(T >= 1) {
        cin>>balls;
        cin>>boxes;

        solve(balls, boxes);
        T--;
    }
}