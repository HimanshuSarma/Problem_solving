// TC: O(N).
// SC: O(1).


#include <bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next = nullptr;
    ListNode(int val) {
        this->val = val;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr && list2 == nullptr) return nullptr;
    else if(list1 == nullptr) return list2;
    else if(list2 == nullptr) return list1;
    else {
        ListNode* head = nullptr;
        if(list1->val > list2->val) {
            head = list2;
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        } else head = list1;
        
        ListNode* l1prev = nullptr;
        ListNode* l2prev = nullptr;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                l1prev = list1;
                list1 = list1->next;
            } else {
                l2prev = list2;
                list2 = list2->next;
                l1prev->next = l2prev;
                l2prev->next = list1;
                l1prev = l2prev;
            }
        }

        if(list1 == nullptr) {
            l1prev->next = list2;
        }

        return head;
    } 
}

int main () {

}