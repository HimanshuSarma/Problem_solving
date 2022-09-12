#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main () {

}