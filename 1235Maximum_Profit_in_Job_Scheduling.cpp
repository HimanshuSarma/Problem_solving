#include <bits/stdc++.h>

using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    const int size = startTime.size();

    int startTimeLowest = INT_MAX;
    int endTimeHighest = -1;

    for (int i = 0; i < endTime.size(); i++) {
        if (endTime[i] > endTimeHighest) endTimeHighest = endTime[i];
        if (startTime[i] < startTimeLowest) startTimeLowest = startTime[i];
    }

    int* dp = new int[(endTimeHighest + 1) * (endTimeHighest + 1)];

    for(int i = 0; i < (endTimeHighest+1); i++) {
        for(int j = 0; j < (endTimeHighest+1); j++) {
            *(dp + i * (endTimeHighest+1) + j) = 0;
        }   
    }

    unordered_map<string, int> umap;

    string temp = "";
    char start, end;

    for (int i = 0; i < startTime.size(); i++) {
        start = startTime[i];
        end = endTime[i];
        temp += start;
        temp += end;
        umap[temp] = profit[i];
        temp = "";
    }

    int difference = 1;

    int i = 0;
    int j = -1;

    int max = 0;
    while (difference <= (endTimeHighest - startTimeLowest)) {
        for (i = startTimeLowest; i <= (endTimeHighest - difference); i++) {
            j = i + difference;
            temp = "";
            start = i;
            end = j;
            temp += start;
            temp += end;

            max = 0;

            std::unordered_map<std::string, int>::const_iterator got = umap.find(temp);
            if (got != umap.end()) {
                max = got->second;
            } 

            for (int k = i+1; k < j; k++) {
                if ((*(dp + i * (endTimeHighest+1) + k) + *(dp + k * (endTimeHighest+1) + j)) > max) {
                    max = (*(dp + i * (endTimeHighest+1) + k) + *(dp + k * (endTimeHighest+1) + j));
                }
            }

            *(dp + i * (endTimeHighest+1) + j) = max;
        }

        difference++;
    }

    // for(int i = 0; i < (endTimeHighest+1); i++) {
    //     for(int j = 0; j < (endTimeHighest+1); j++) {
    //         if (*(dp + i * (endTimeHighest+1) + j) == 998) cout<<i<<" "<<j<<" "<<"yes"<<endl; 
    //         // cout<<*(dp + i * (endTimeHighest+1) + j)<<" ";
    //     }   
    // }

    cout<<*(dp + startTimeLowest * (endTimeHighest+1) + endTimeHighest);
    return *(dp + startTimeLowest * (endTimeHighest+1) + endTimeHighest);
}

int main () {
    vector<int> startTime = {341,22,175,424,574,687,952,439,51,562,962,890,250,47,945,914,835,937,419,343,125,809,807,959,403,861,296,39,802,562,811,991,209,375,78,685,592,409,369,478,417,162,938,298,618,745,888,463,213,351,406,840,779,299,90,846,58,235,725,676,239,256,996,362,819,622,449,880,951,314,425,127,299,326,576,743,740,604,151,391,925,605,770,253,670,507,306,294,519,184,848,586,593,909,163,129,685,481,258,764};
    vector<int> endTime = {462,101,820,999,900,692,991,512,655,578,996,979,425,893,975,960,930,991,987,524,208,901,841,961,878,882,412,795,937,807,957,994,963,716,608,774,681,637,635,660,750,632,948,771,943,801,985,476,532,535,929,943,837,565,375,854,174,698,820,710,566,464,997,551,884,844,830,916,970,965,585,631,785,632,892,954,803,764,283,477,970,616,794,911,771,797,776,686,895,721,917,920,975,984,996,471,770,656,977,922};
    vector<int> profit = {85,95,14,72,17,3,86,65,50,50,42,75,40,87,35,78,47,74,92,10,100,29,55,57,51,34,10,96,14,71,63,99,8,37,16,71,10,71,83,88,68,79,27,87,3,58,56,43,89,31,16,9,49,84,62,30,35,7,27,34,24,33,100,25,90,79,58,21,31,30,61,46,36,45,85,62,91,54,28,63,50,69,48,36,77,39,19,97,20,39,48,72,37,67,72,46,54,37,53,30};
    jobScheduling(startTime, endTime, profit);
}