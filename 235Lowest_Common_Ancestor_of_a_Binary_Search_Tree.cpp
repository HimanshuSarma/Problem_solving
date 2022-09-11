// Approach 1: 
// TC: height + height + height. The first logN to search for p, and second logN to search for q
//     and then we are popping the stacks of both p and q untill the TOS of both p and q are equal
//     and the maximum size of stack of both p and q will be height of the tree.
//     So, TC = O(height)

// SC: O(height) Recursive call stack.
// Approach 1

// Approach 2:
// TC: height or O(height).

// SC: O(height) Recursive call stack.
// Approach 2

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Approach 1.
stack<TreeNode*> pStack, qStack;

void lowestCommonAncestorHelper(TreeNode* root, TreeNode* key, char pOrQ) {
    if(root == key) {
        if(pOrQ == 'p') pStack.push(root);
        else qStack.push(root);
        return;
    } else if(root->val < key->val) {
        if(pOrQ == 'p') pStack.push(root);
        else qStack.push(root);
        lowestCommonAncestorHelper(root->right, key, pOrQ);
    } else {
        if(pOrQ == 'p') pStack.push(root);
        else qStack.push(root);
        lowestCommonAncestorHelper(root->left, key, pOrQ);
    } 
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    lowestCommonAncestorHelper(root, p, 'p');
    lowestCommonAncestorHelper(root, q, 'q');

    if(pStack.size() == qStack.size()) {
        while(pStack.top() != qStack.top()) {
            pStack.pop();
            qStack.pop();
        }

        return pStack.top();
    } else if(pStack.size() > qStack.size()) {
        while(pStack.size() != qStack.size()) {
            pStack.pop();
        }
    } else {
        while(pStack.size() != qStack.size()) {
            qStack.pop();
        }
    }

    while(pStack.top() != qStack.top()) {
        pStack.pop(); qStack.pop();
    }
    return pStack.top();
}
// Approach 1.

// Approach 2.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    else if((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val)) return root;
    else if(p->val > root->val) { // We know for sure that p and q will be on the same side of the root
                                  // i.e., either the left subtree of root or the right subtree of root...
        return lowestCommonAncestor(root->right, p, q);
    } else return lowestCommonAncestor(root->left, p, q);
}
// Approach 2.

int main () {

}