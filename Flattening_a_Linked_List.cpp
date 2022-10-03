#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// Node *flatten(Node *head) {
//    Node* processing = head;
//    Node* pointer1 = head;
// //    Node* pointer2 = head->next;
//    Node* bottomTrav = nullptr;
//    while(processing) {
//     if(processing->bottom) {
//         pointer1 = processing;
//         while(processing->bottom) {
//             bottomTrav = processing->bottom;
//             Node* lastSatisfiedNode = nullptr;
//             while(bottomTrav && bottomTrav->data >= pointer1->data && 
//             pointer1->next && bottomTrav->data <= pointer1->next->data) {
//                 bottomTrav->next = bottomTrav->bottom;
//                 bottomTrav->bottom = nullptr;
//                 lastSatisfiedNode = bottomTrav;
//                 bottomTrav = bottomTrav->next;
//             }

//             Node* bottomStart = processing->bottom;
//             if(bottomStart != bottomTrav) {
//                 processing->bottom = bottomTrav;
//                 lastSatisfiedNode->next = pointer1->next;
//                 pointer1->next = bottomStart; 
//                 pointer1 = lastSatisfiedNode->next; 
//             } else {
//                 if(!pointer1->next) {
//                     while(bottomTrav->bottom) {
//                         bottomTrav->next = bottomTrav->bottom;
//                         bottomTrav->bottom = nullptr;
//                         bottomTrav = bottomTrav->next;
//                     }

//                     pointer1->next = bottomStart;
//                     processing->bottom = nullptr;
//                 } else pointer1 = pointer1->next;
//             }
//         }

//         processing = processing->next;
//     } else {
//         processing = processing->next;
//     }
//    }

//    return head;
// }


Node* flatten(Node* head) {
	if(!head->next) return head;

	Node* l1Head = head; 
	Node* l2Head = l1Head->next;
	Node* l1 = head;
	Node* l1Prev = nullptr;
	Node* l2 = l1->next;
	Node* l2Prev = nullptr;
	Node* l1Temp = nullptr;
	Node* l2Temp = nullptr;

	Node* merged = nullptr;

	while(true) {
		bool start = true;
		l1Head = l1;
		l2Head = l2;
		while(l1 && l2) {
			if(l1->data <= l2->data) {
				if(start) {
					merged = l1;
					l1Prev = l1;
					l1 = l1->bottom;
					start = false;
				} else {
					if(merged != l1Head) {
						l1Temp = l1->bottom;
						l1->bottom = l2;
						l2Prev->bottom = l1;
						l1 = l1Temp;
						l1Prev = nullptr;
						l2Prev = l2Prev->bottom;
					} else {
						l1Prev = l1;
						l1 = l1->bottom;
					}
				}
			} else {
				if(start) {
					merged = l2;
					l2Prev = l2;
					l2 = l2->bottom;
					start = false;
				} else {
					if(merged == l1Head) {
						l2Temp = l2->bottom;
						l2->bottom = l1;
						l1Prev->bottom = l2;
						l2 = l2Temp;
						l2Prev = nullptr;
						l1Prev = l1Prev->bottom;
					} else {
						l2Prev = l2;
						l2 = l2->bottom;
					}
				}
			}
		}

		if(l1) {
			while(l1) {
				if(merged != l1Head) {
					l1Temp = l1->bottom;
					l1->bottom = l2Prev->bottom;
					l2Prev->bottom = l1;
					l2Prev = l2Prev->bottom;
					l1 = l1Temp;
				} else {
					break;
				}
			}
		} else {
			while(l2) {
				if(merged == l1Head) {
					l2Temp = l2->bottom;
					l2->bottom = l1Prev->bottom;
					l1Prev->bottom = l2;
					l1Prev = l1Prev->bottom;
					l2 = l2Temp;
				} else {
					break;
				}
			}
		}

		if(merged == l1Head) {
			l1 = merged;
			l2 = l2Head->next;
		} else {
			l1 = l2Head;
			l2 = l2Head->next;
		}

		if(!l1 || !l2) {
			return merged;
		}
	}
}

int main() {

}