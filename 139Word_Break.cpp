#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    const int size = s.size();
    bool* dp = new bool[(size + 1) * (size + 1)];
    unordered_map<string, bool> umap;

    string temp = "";
    for (int i = 0; i < wordDict.size(); i++) {
        temp = wordDict[i];
        umap[wordDict[i]] = true;
    }

    int difference = 0;

    int j = 0;
    while(difference <= size - 1) {
        for (int i = 1; i <= size - difference; i++) {
            j = i + difference;
            if(difference == 0) {
                temp = s.substr(i-1, 1);
                if (umap.find(temp) == umap.end()) {
                    *(dp + i * (size+1) + j) = false;
                } else {
                    *(dp + i * (size+1) + j) = true;
                }
            } else {
                temp = s.substr(i-1, j-i+1);
                if (umap.find(temp) != umap.end()) {
                    *(dp + i * (size+1) + j) = true;
                    continue;
                } 

                for (int k = i; k < j; k++) {
                    if (*(dp + i * (size+1) + k) && *(dp + (k+1) * (size+1) + j)) {
                        *(dp + i * (size+1) + j) = true;
                        break;
                    } else if (k == j - 1) {
                        *(dp + i * (size+1) + j) = false;
                    }
                }
            }
        }

        difference++;
    }  

    return *(dp + 1 * (size+1) + size);
}

int main () {
    vector<string> wordDict = {"leet","code"};
    wordBreak("leetcode", wordDict);
}