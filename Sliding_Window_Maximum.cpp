#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* prev;
    Node* next;
    int val;
    int idx;

    Node (int val, int idx) {
        this->val = val;    
        this->idx = idx;
        this->prev = nullptr;
        this->next = nullptr;
    }
};  

class List {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertAtSortedPosition (int val, int idx) {

        //<<1213<<endl;

        Node* newNode = new Node(val, idx);

        if (!this->head) {
            this->head = newNode;
            this->tail = head;
        } else {
            Node* trav = this->tail;
            Node* travTrailer = nullptr;

            // //<<28<<trav->val<<endl;

            while (trav && (trav->val < val)) {
                travTrailer = trav;
                trav = trav->prev;
                tail = trav;
                delete travTrailer;
                travTrailer = nullptr;
                if (tail == nullptr) {
                    head = newNode;
                    tail = newNode;
                    return;
                }
            }

            if (trav == tail) {
                newNode->prev = trav;
                trav->next = newNode;
                tail = newNode;
            } else if (trav == nullptr) {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            } else {
                travTrailer->prev = newNode;
                newNode->next = travTrailer;
                newNode->prev = trav;
            }
            
        }

        //<<1415<<endl;
    }

    void deleteFront () {

        Node* temp = head;

        if (head != tail) {
            head = head->next;
            head->prev = nullptr;
            delete temp;
            temp = nullptr;
            return;
        }

    }

    void deleteOutOfBoundElements (int upper_bound, int lower_bound, int val) {

        Node* trav = head;

        while (trav != nullptr && (trav->idx < lower_bound || trav->idx > upper_bound)) {

            head = head->next;
            if (head) head->prev = nullptr;
            else {
                head = nullptr;
                tail = nullptr;
            }
            delete trav;
            trav = head;

        }

    }

    void deleteElementsLessThanGivenElement (int val) {

        // //<<678<<endl;

        Node* trav = tail;
        Node* travTrailer = nullptr;

        while (trav && trav->val <= val) {

            travTrailer = trav;
            trav = trav->prev;

            tail = trav;
            delete travTrailer;
            travTrailer = nullptr;

            if (tail == nullptr) head  = nullptr;

        }

        //<<910<<endl;

    }

};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> ans(nums.size() -k +1);
    int currentAnsIdx = 0;
    int n = nums.size();

    List* ll = new List();

    for(int i = 0; i < n; i++) {

        //<<222<<i<<endl;

        if (i < k) {

            ll->insertAtSortedPosition(nums[i], i);
            // //<<123<<endl<<ll->head->val<<endl<<ll->tail->val<<endl;

            if (i == k-1) {
                ans[currentAnsIdx] = ll->head->val;
                currentAnsIdx++;
                if (ll->head->idx == (i-k+1)) {
                    ll->deleteFront();
                }
            }

        } else {

            ll->deleteOutOfBoundElements(i, i-k+1, nums[i]);
            // ll->deleteElementsLessThanGivenElement(nums[i]);

            ll->insertAtSortedPosition(nums[i], i);
            ans[currentAnsIdx] = ll->head->val;
            currentAnsIdx++;
            if (ll->head->idx == (i-k+1)) {
                ll->deleteFront();
            }

        }

        //<<111<<endl;

    }


    return ans;

}


int main () {

    vector<int> nums = {1, -1};
    vector<int> ans = maxSlidingWindow(nums, 1);

    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

}