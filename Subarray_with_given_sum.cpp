#include <bits/stdc++.h>

using namespace std;

vector<int> answerFormatter(int ans1, int ans2) {

    vector<int> answer(2, 0);

    answer[0] = ans1 + 1;
    answer[1] += ans2 + 1;

    return answer;
}

vector<int> subarraySum(vector<int>arr, int n, long long s) {
    long long int runningSum = 0;
    int startingIdx = 0;

    vector<int> answer(2, 0);

    if (s > 0) {
        for (int i = 0; i < n; i++) {
            runningSum += arr[i];
            if (runningSum == s) {
                return answerFormatter(startingIdx, i);     
            } else if (runningSum > s) {
                for (int j = startingIdx; j <= i; j++) {
                    runningSum -= arr[j];
                    startingIdx += 1;
                    if (runningSum == s) {
                        return answerFormatter(startingIdx, i);     
                    } else if (runningSum < s) {
                        break;
                    }
                }
            }
        }
    }

    vector<int> noAnswer(1, -1);
    return noAnswer;
}

int main () {
    vector<int> arr = {1, 2, 3, 7, 5};
    vector<int> result = subarraySum(arr, arr.size(), 12);
    cout<<result[0]<<" "<<result[1]<<endl;
}