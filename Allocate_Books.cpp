#include <bits/stdc++.h>

using namespace std;

// Approach 1...
// map<pair<int, int>, int> lastStudentSum;

// void booksHelperRec(int A[], int n1, int maxSoFar, int booksUsedSoFar, int B, int currentStudent, int& minimum,
//     int low) {
//     if(currentStudent == B) {
//         // End of recursion...
//         if(maxSoFar <= minimum) minimum = maxSoFar;
//         return;
//     } else if(currentStudent <= B-2) {
//         int totalPages = 0;
//         int i = booksUsedSoFar;
//         for(; i < n1; i++) {
//             booksUsedSoFar += 1;
//             totalPages += A[i];
//             if(totalPages > maxSoFar) maxSoFar = totalPages;
//             if(n1 - booksUsedSoFar >= (B - (currentStudent+1))) {
//                 booksHelperRec(A, n1, maxSoFar, booksUsedSoFar, B, currentStudent+1, minimum, low);
//             } else break;
//         }
//     } else if(currentStudent == B-1) {
//         int totalPages = 0;
//         int i = booksUsedSoFar;
//         low = booksUsedSoFar;
//         auto iterator = lastStudentSum.find({low-1, n1-1});
//         if(iterator == lastStudentSum.end()) {
//             for(i; i < n1; i++) {
//                 totalPages += A[i];
//             }

//             lastStudentSum.insert({{low, n1-1}, totalPages});
//         } else {
//             totalPages = iterator->second - A[low-1];
//             lastStudentSum.insert({{low, n1-1}, totalPages});
//         }

//         booksUsedSoFar += n1 - booksUsedSoFar;
//         if(totalPages > maxSoFar) maxSoFar = totalPages;
//         booksHelperRec(A, n1, maxSoFar, booksUsedSoFar, B, currentStudent+1, minimum, low);
//     }
// }

// int findPages(int A[], int n1, int B) {
//     if(n1 < B) return -1;
//     int booksUsedSoFar = 0;
//     int maxSoFar = 0;
//     int minimum = INT_MAX;
//     booksHelperRec(A, n1, maxSoFar, booksUsedSoFar, B, 0, minimum, 0);
//     return minimum;
// }
// Approach 1.



// Approach 2...
// Approach 2 Helper Recursive...
bool findPagesHelperRec(int A[], int n1, int maxSoFar, int& booksUsedSoFar, int B, int currentStudent, 
    int potentialAns) {
        
    if(currentStudent == B) {
        // End of recursion...
        return true;
    } else if(currentStudent <= B-1) {
        int totalPages = 0;
        int i = booksUsedSoFar;
        while(n1 - (booksUsedSoFar + 1) >= (B - (currentStudent+1))) {
            totalPages += A[booksUsedSoFar];
            booksUsedSoFar += 1;
            if(totalPages > potentialAns) {
                if(currentStudent == B-1) {
                    return false;
                }
                totalPages -= A[i];
                booksUsedSoFar -= 1;
                return findPagesHelperRec(A, n1, maxSoFar, booksUsedSoFar, B, currentStudent+1, potentialAns);
                // maxSoFar = totalPages;
            } 
        }

        return findPagesHelperRec(A, n1, maxSoFar, booksUsedSoFar, B, currentStudent+1, potentialAns);
    }
}
// Approach 2 Helper Recursive

// Approach 2 Helper iterative...
bool findPagesHelper(int A[], int n1, int B, int potentialAns) {
    int booksUsedSoFar = 0, currentStudent = 0;
    int totalPages = 0;

    while(currentStudent < B) {
        totalPages = 0;
        while(n1 - (booksUsedSoFar + 1) >= (B - (currentStudent+1))) {
            totalPages += A[booksUsedSoFar];
            booksUsedSoFar += 1;
            if(totalPages > potentialAns) {
                if(currentStudent == B-1) {
                    return false;
                }
                booksUsedSoFar -= 1;
                break;
            } 
        }

        currentStudent++;
    }

    return true;
}
// Approach 2 Helper iterative.

int findPages(int A[], int n1, int B) {
    if(n1 < B) return -1;
    int ans;
    int maxSoFar = 0, sum = 0, maxOfArr = A[0];
    for(int i = 0; i < n1; i++) {
        if(A[i] > maxOfArr) maxOfArr = A[i];
        sum += A[i];
    }

    int low = maxOfArr, high = sum, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(findPagesHelper(A, n1, B, mid)) {
            ans = mid;
            high = ans - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
// Approach 2...


int main () {
    int size;
    cin>>size;
    int A[size];
    for(int i = 0; i < size; i++) {
        cin>>A[i];
    }

    cout<<endl<<findPages(A, size, 2);
}