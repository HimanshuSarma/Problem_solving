#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class returnVal {
public:
    TreeNode* node1;
    TreeNode* node2;
    TreeNode* parent1;
    TreeNode* parent2;
    returnVal() {
        node1 = nullptr;
        node2 = nullptr;
        parent1 = nullptr;
        parent2 = nullptr;
    };
};

returnVal val;

returnVal isValidBSTApproach1(TreeNode* currentNode, TreeNode* lowerBound, TreeNode* upperBound) {

    if(currentNode->val <= lowerBound->val || currentNode->val >= upperBound->val) {
        if (val.node1 == nullptr) {
            val.node1 = currentNode;
            if (currentNode->val <= lowerBound->val) val.parent1 = lowerBound;
            else if (currentNode->val >= upperBound->val) val.parent1 = upperBound;
        } 
        else {
            val.node2 = currentNode;
            if (currentNode->val <= lowerBound->val) val.parent2 = lowerBound;
            else if (currentNode->val >= upperBound->val) val.parent2 = upperBound;
            return val;
        }
    }

    if(currentNode->left) {
        val = isValidBSTApproach1(currentNode->left, lowerBound, currentNode);
        if (val.node2 != nullptr) return val;
    }

    if(currentNode->right) {
        val = isValidBSTApproach1(currentNode->right, currentNode, upperBound);
        if (val.node2 != nullptr) return val;
    }

    return val;
}

void traverseTree (TreeNode* curr) {

    cout<<curr->val<<" ";
    if(curr->left) traverseTree(curr->left);
    if(curr->right) traverseTree(curr->right);

}

void recoverTree(TreeNode* root) {

    TreeNode* lowerBound = new TreeNode(-2147483648);
    TreeNode* upperBound = new TreeNode(2147483647);
    returnVal val = isValidBSTApproach1(root, lowerBound, upperBound);
    // cout<<val.node->val<<" "<<val.parent->val<<endl;
    
    if (val.node2 == nullptr) {
        int temp = val.node1->val;
        val.node1->val = val.parent->val;
        val.parent->val = temp;
    } else {
        int temp = val.node2->val;
        val.node2->val = val.node1->val;
        val.node1->val = temp;
    }

    traverseTree(root);
}

int main () {
    TreeNode* root = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(1);
    // root->right->left = new TreeNode(2);

    recoverTree(root);
}