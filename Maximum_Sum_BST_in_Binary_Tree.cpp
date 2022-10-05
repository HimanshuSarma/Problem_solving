// TC: Visting every node exactly once. So, complexity is O(N).
// SC: O(N) (Worst case if tree is skewed.)


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

class returnVal {
public:
    int sum;
    int totalSum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    bool isBST = false;
};

int maxOfTwo(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int maxOfThree(int a, int b, int c) {
    return maxOfTwo(c, maxOfTwo(a, b));
}

int minOfTwo(int a, int b) {
    if(a <= b) return a;
    else return b;
}

int minOfThree(int a, int b, int c) {
    return minOfTwo(c, minOfTwo(a, b));
}

bool postitiveNodes = false;

returnVal maxSumBSTHelper(TreeNode* root, TreeNode* currentNode) {
    if(currentNode->val >= 0) postitiveNodes = true;
    returnVal currentNodeReturn;
    returnVal leftReturn;
    returnVal rightReturn;

    if(!currentNode->left && !currentNode->right) {
        if(currentNode == root && !postitiveNodes) {
            currentNodeReturn.isBST = false;
            currentNodeReturn.sum = 0;
            currentNodeReturn.totalSum = currentNode->val;
            return currentNodeReturn;
        }

        currentNodeReturn.isBST = true;
        currentNodeReturn.sum = currentNode->val;
        currentNodeReturn.totalSum = currentNode->val;
        currentNodeReturn.min = currentNode->val;
        currentNodeReturn.max = currentNode->val;
        return currentNodeReturn;
    }

    if(currentNode->left) {
        leftReturn = maxSumBSTHelper(root, currentNode->left);
    } else {
        leftReturn.isBST = true;
        leftReturn.sum = 0;
        leftReturn.totalSum = 0;
    }

    if(currentNode->right) {
        rightReturn = maxSumBSTHelper(root, currentNode->right);
    } else {
        rightReturn.isBST = true;
        rightReturn.sum = 0;
        rightReturn.totalSum = 0;
    }

    if(!leftReturn.isBST || !rightReturn.isBST) {
        if(currentNode == root && !postitiveNodes) {
            currentNodeReturn.isBST = false;
            currentNodeReturn.sum = 0;
            return currentNodeReturn;
        }
        currentNodeReturn.isBST = false;
        currentNodeReturn.sum = maxOfTwo(leftReturn.sum, rightReturn.sum);
        currentNodeReturn.totalSum = currentNode->val + leftReturn.totalSum + rightReturn.totalSum;
        currentNodeReturn.min = minOfThree(currentNode->val, leftReturn.min, rightReturn.min);
        currentNodeReturn.max = maxOfThree(currentNode->val, leftReturn.max, rightReturn.max);
    } else {
        if(currentNode == root && !postitiveNodes) {
            currentNodeReturn.isBST = false;
            currentNodeReturn.sum = 0;
            return currentNodeReturn;
        } else if(leftReturn.isBST && rightReturn.isBST && 
            ((currentNode->left && currentNode->val > leftReturn.max) || (!currentNode->left)) &&
            ((currentNode->right && currentNode->val < rightReturn.min) || (!currentNode->right))) {
            currentNodeReturn.isBST = true;
            currentNodeReturn.sum = maxOfThree(leftReturn.sum, 
            leftReturn.totalSum + currentNode->val + rightReturn.totalSum, rightReturn.sum);
        } else {
            currentNodeReturn.isBST = false;
            currentNodeReturn.sum = maxOfTwo(leftReturn.sum, rightReturn.sum);
        }

        currentNodeReturn.totalSum = currentNode->val + leftReturn.totalSum + rightReturn.totalSum;
        currentNodeReturn.min = minOfThree(currentNode->val, leftReturn.min, rightReturn.min);
        currentNodeReturn.max = maxOfThree(currentNode->val, leftReturn.max, rightReturn.max);
        return currentNodeReturn;
    }

    return currentNodeReturn;
}

int maxSumBST(TreeNode* root) {
    return maxSumBSTHelper(root, root).sum;
}


int main () {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(6);
    root->left->left->left = new TreeNode(9);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(-5);
    root->left->right->left->right = new TreeNode(-3);
    root->left->right->right = new TreeNode(4);
    root->left->right->right->right = new TreeNode(10);

    cout<<maxSumBST(root);
}