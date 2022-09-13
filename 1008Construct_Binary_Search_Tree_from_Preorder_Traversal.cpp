// Approach 1: 
// TC: O(n*h). This is a loose upper bound, because all of the left child nodes will take just constant time.
// SC: O(h). Stack space.
// Approach 1

// Approach 2:
// TC: O(N). Because we will have a recursive call on every node of the bst, and the time required in every 
//     recursive call is just constant.
// SC: O(h). The maximum depth of the recursive call stack will be h.
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

// Approach 2: using recursion..
void bstFromPreorderHelper(TreeNode* root, int& currentNode, int upperBound, vector<int>& preorder) {
    if(currentNode > preorder.size() - 1) return;
    if(preorder[currentNode] < root->val) {
        root->left = new TreeNode(preorder[currentNode]);
        currentNode += 1;
        if(currentNode > preorder.size() - 1) return;
        bstFromPreorderHelper(root->left, currentNode, root->val, preorder);
    } 
    
    if(currentNode > preorder.size() - 1) return;
    if(preorder[currentNode] < upperBound) {
        root->right = new TreeNode(preorder[currentNode]);
        currentNode += 1;
        if(currentNode > preorder.size() - 1) return;
        bstFromPreorderHelper(root->right, currentNode, upperBound, preorder);
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    int currentNode = 1;
    bstFromPreorderHelper(root, currentNode, INT_MAX, preorder);
    return root;
}
// Approach 2: using recursion..


// Approach 1: Using stack...
stack<TreeNode*> preorderTraversal;

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    preorderTraversal.push(root);
    TreeNode* tos1 = root; TreeNode* tos2 = nullptr;
    for(int i = 1; i < preorder.size(); i++) {
        if(preorder[i] < tos1->val) {
            tos1->left = new TreeNode(preorder[i]);
            preorderTraversal.push(tos1->left);
            tos1 = tos1->left;
        } else if(preorder[i] > tos1->val) {
            while (preorder[i] > tos1->val) {
                preorderTraversal.pop();
                if(preorderTraversal.empty()) {
                    tos1->right = new TreeNode(preorder[i]);
                    preorderTraversal.push(tos1->right);
                    tos1 = tos1->right;
                    break;
                }
                tos2 = preorderTraversal.top();
                if(preorder[i] > tos2->val) {
                    tos1 = tos2;
                } else if(preorder[i] < tos2->val) {
                    tos1->right = new TreeNode(preorder[i]);
                    preorderTraversal.push(tos1->right);
                    tos1 = tos1->right;
                    break;
                }
            }
        }
    }

    return root;
}
// Approach 1: Using stack...

int main () {

}