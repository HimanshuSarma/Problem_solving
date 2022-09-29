#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxOfTwo(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int isBalancedHelper(TreeNode* root, int currentHeight) {
    int leftHeight, rightHeight;

    if(!root->left) {
        leftHeight = currentHeight;
    }
    else {
        leftHeight = isBalancedHelper(root->left, currentHeight+1);
        if(leftHeight < 0) return -1;
    }

    if(!root->right) {
        rightHeight = currentHeight;
    }
    else {
        rightHeight = isBalancedHelper(root->right, currentHeight+1);
        if(rightHeight < 0) return -1; 
    }

    if(abs(leftHeight - rightHeight) > 1) return -1;
    else return maxOfTwo(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    if(!root) return true;
    if(isBalancedHelper(root, 0) < 0) return false;
    else return true;
}

int main() {
    
}