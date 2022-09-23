#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool helper1Rec(ll length, ll currentLevel, ll a, ll b, int* arr) {
    // cout<<"currentLevel"<<currentLevel<<endl;
    if(currentLevel < 0 || currentLevel > 9) return false; 
    if(length % 2 == 0 && currentLevel > (length / 2) - 1) return true;
    else if(length % 2 != 0 && currentLevel > (length / 2)) return true;

    if(a + b == 1) {
        if(b == 1) arr[currentLevel] = 1;
        else arr[currentLevel] = 0;
        return helper1Rec(length, currentLevel+1, 0, 0, arr);
    } 
    else if(a >= 2) {
        arr[currentLevel] = 0;
        return helper1Rec(length, currentLevel+1, a-2, b, arr);
    } else if(b >= 2) {
        arr[currentLevel] = 1;
        return helper1Rec(length, currentLevel+1, a, b-2, arr);
    } else {
        return false;
    }
}  

bool helper2Rec(ll length, ll currentLevel, ll a, ll b, int* arr, bool isDifferent) {
    // cout<<"currentLevel"<<currentLevel<<endl;
    if(currentLevel < 0 || currentLevel > 9) return false; 
    if(length % 2 == 0 && currentLevel > (length / 2) - 1 && isDifferent) return true;
    else if(length % 2 != 0 && currentLevel > (length / 2) && isDifferent) return true;

    if(a + b == 1) {
        if(isDifferent) return helper2Rec(length, currentLevel+1, 0, 0, arr, isDifferent);
        else {
            if(b == 1) {
                if(arr[currentLevel == 1]) return false;
                else return true;
            } else if(arr[currentLevel] == 0) return false;
            else return true;
        }   
    }

    if(isDifferent) {
        if(a >= 2) {
            return helper2Rec(length, currentLevel+1, a-2, b, arr, true);
        } else if(b >= 2) {
            return helper2Rec(length, currentLevel+1, a, b-2, arr, true);
        } else return false;
    } else {
        if(a >= 2 && arr[currentLevel] != 0) {
            return helper2Rec(length, currentLevel+1, a-2, b, arr, true);
        } else if(a >= 2 && b >= 2) {
            return helper2Rec(length, currentLevel+1, a, b-2, arr, true);
        } else return false;
    }
}

void solve(ll a, ll b) {
    int* arr = nullptr;
    if(a+b % 2 == 0) {
        arr = new int[(a+b) / 2];
    } else {
        arr = new int[((a+b) / 2) + 1];
    }

    arr = new int[10];
    if(!helper1Rec(a+b, 0, a, b, arr)) {
        cout<<"no"<<endl;
        return;
    } 
    if(helper2Rec(a+b, 0, a, b, arr, false)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

int main() {
    ll T, a, b;
    cin>>T;
    while(T >= 1) {
        cin>>a>>b; 
        solve(a, b);
        T--;
    }
}