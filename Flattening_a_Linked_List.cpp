// TC: Let's say on an average there are N nodes in every bottom list, and the total nodes in the main
//     list is M, then the time required to merge the first two lists is N+N = 2N.
//     Then, merging the result(size 2N) with the next list(size N) will take 2N + N = 3N time.
//     Then, merging the result(size 3N) with the next list(size N) will take 3N + N = 4N time.
//     Then, merging the result(size 4N) with the next list(size N) will take 4N + N = 5N time.
//     ......
//     Then, merging the result(size (M-1)N) with the last list(size N) will take (M-1)N + N = MN time.

//     Adding all of them, we get 2N + 3N + 4N + 5N + .... + MN = (2+3+4+5+...+M)N = O(M^2N)
//     So, time required is O(M^2N).

// SC: O(1).
 

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