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

void serializeHelper(TreeNode* root, string& encodedBinaryTree) {
    ostringstream str;
    str << root->val;
    encodedBinaryTree += str.str() + ",";

    if(root->left) {
        serializeHelper(root->left, encodedBinaryTree);
    } else {
        encodedBinaryTree += "*,";
    }

    if(root->right) {
        serializeHelper(root->right, encodedBinaryTree);
    } else {
        encodedBinaryTree += "*,";
    }
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root) return "";
    string encodedBinaryTree = "";
    serializeHelper(root, encodedBinaryTree);
    return encodedBinaryTree;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data == "") return nullptr;  
    stack<TreeNode*> preorder_stack;
    TreeNode* root = nullptr;
    string currentNumberStr = "";
    int currentNumber;
    TreeNode* currentNode = nullptr;
    int i = 0;
    while(i < data.length()) {
        while(data[i] != ',') {
            currentNumberStr += data[i];
            i++;
        }

        currentNumber = stoi(currentNumberStr);
        root = new TreeNode(currentNumber);
        preorder_stack.push(root);
        i++;
        break;
    }

    while(!preorder_stack.empty()) {
        currentNode = preorder_stack.top();
        if(data[i] != '*') {
            currentNumberStr = "";
            while(data[i] != ',') {
                currentNumberStr += data[i];
                i++;
            }
            i++;
            currentNumber = stoi(currentNumberStr);
            currentNode->left = new TreeNode(currentNumber);
            preorder_stack.push(currentNode->left);
        } else if(data[i] == '*') {
            i += 2;
            while(i < data.length() && data[i] == '*') {
                preorder_stack.pop();
                if(preorder_stack.empty()) return root;
                currentNode = preorder_stack.top();
                i += 2;
            }

            if(i >= data.length()) return root;
            currentNumberStr = "";
            while(data[i] != ',') {
                currentNumberStr += data[i];
                i++;
            }
            i++;
            currentNumber = stoi(currentNumberStr);
            currentNode->right = new TreeNode(currentNumber);
            preorder_stack.pop();
            preorder_stack.push(currentNode->right);
        }
    }

    return root;
}

int main() {
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(-7);
    // root->right = new TreeNode(-3);
    // root->right->left = new TreeNode(-9);
    // root->right->right = new TreeNode(-3);
    // root->right->left->left = new TreeNode(9);
    // root->right->left->left->left = new TreeNode(6);
    // root->right->left->left->left->left = new TreeNode(0);
    // root->right->left->left->left->left->right = new TreeNode(-1);
    // root->right->left->left->left->right = new TreeNode(6);
    // root->right->left->left->left->right->left = new TreeNode(-4);
    // root->right->left->right = new TreeNode(-7);
    // root->right->left->right->left = new TreeNode(-6);
    // root->right->left->right->left->left = new TreeNode(5);
    // root->right->left->right->right = new TreeNode(-6);
    // root->right->left->right->right->left = new TreeNode(9);
    // root->right->left->right->right->left->left = new TreeNode(-2);
    // root->right->right->left = new TreeNode(-4);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    deserialize(serialize(root));
}