#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    int i = 0, j = 1;
    while(j < needle.size()) {
        if(needle[i] == needle[j]) {
            lps[j] = i+1;
            j++; 
            i++;
        } else {
            j++;
        }
    }

    for(int i = 0; i < lps.size(); i++) {
        cout<<lps[i]<<" ";
    }
    cout<<endl;

    i = 0; j = -1;
    while(i < haystack.size()) {
        if(haystack[i] == needle[j+1]) {
            i++; j++;
            if(j == (needle.size() - 1)) return (i - needle.size());
        } else {
            if(j >= 0) {
                j = lps[j];
            }

            i++;
        }
    }

    return -1;
}

int main() {
    string haystack = "babba", needle = "bbb";
    cout<<strStr(haystack, needle);
}