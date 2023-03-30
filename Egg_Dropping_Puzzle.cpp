#include <bits/stdc++.h>

using namespace std;

int eggDrop(int n, int k) {
    int* dp = new int[(n+1) * (k+1)];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) {
                *(dp + i * k + j) = -1;
            } else if (i == 1) {
                *(dp + i * k + j) = j;
            } else if (j == 0) {
                *(dp + i * k + j) = 0;
            } else if (j == 1) {
                *(dp + i * k + j) = 1;
            } else {
                
            }
        }
    }    
}

int main () {

}