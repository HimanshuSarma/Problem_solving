// TC: O(N) both the appproaches. We have to visit every node in the tree exactly once.
// SC: For recursive call stack.
// Worst case O(N) when there is only 1 node in every level.
// Best case O(logN) when it is a perfect binary tree.


#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};



bool isValidBSTApproach1(TreeNode* root, long int lowerBound = -2147483649, long int upperBound = 2147483648) {
    bool leftValidity = true;
    bool rightValidity = true;

    if(root->val <= lowerBound || root->val >= upperBound) {
        return false;
    }

    if(root->left) {
        leftValidity = isValidBSTApproach1(root->left, lowerBound, root->val);
    } else if(root->left) return false;

    if(root->right) {
        rightValidity = isValidBSTApproach1(root->right, root->val, upperBound);
    } else if(root->right) return false;


    return leftValidity && rightValidity;
}

bool isValidBSTApproach2(TreeNode* root, long int compareVal = -1, int parentVal = -1, char LOrR = 'a') {
    bool leftValidity = true;
    bool rightValidity = true;

    if(LOrR == 'a') {
        if(root->left) {
            leftValidity = isValidBSTApproach2(root->left, -2147483649, root->val, 'l');
        } 

        if(root->right) {
            rightValidity = isValidBSTApproach2(root->right, 2147483648, root->val, 'r');
        } 
    } 

    if(LOrR == 'l' && (root->val < parentVal && root->val > compareVal)) {
        if(root->left) {
            leftValidity = isValidBSTApproach2(root->left, compareVal, root->val, 'l');
        }

        if(root->right) {
            rightValidity = isValidBSTApproach2(root->right, parentVal, root->val, 'r');
        } 
    } else if(LOrR == 'l') return false;

    if(LOrR == 'r' && (root->val > parentVal && root->val < compareVal)) {
        if(root->left) {
            leftValidity = isValidBSTApproach2(root->left, parentVal, root->val, 'l');
        }

        if(root->right) {
            rightValidity = isValidBSTApproach2(root->right, compareVal, root->val, 'r');
        } 
    } else if(LOrR == 'r') return false;

    return leftValidity && rightValidity;
}

int main () {
    TreeNode* root = new TreeNode(-2147483648);
    root->right = new TreeNode(2147483647);
}