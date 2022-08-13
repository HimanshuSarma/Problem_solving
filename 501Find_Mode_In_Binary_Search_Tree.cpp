//Approach 1:
//TC: O(N) (Assuming that accessing the hash map takes O(1) time). 
//    N time for traversal of the entire tree, the two loops of O(N) each, so total 3N or O(N).

//SC: O(N) For the hash map.


//Approach 2:
//TC: O(N). For inorder traversal of the tree...
//SC: O(1). No extra space used...

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

unordered_map<int, int> nodeOccurence;

void findModeHelperApproach1(TreeNode* root) {
    if(nodeOccurence.find(root->val) == nodeOccurence.end()) {
        nodeOccurence[root->val] = 1;
    } else {
        nodeOccurence[root->val] += 1;
    }

    if(root->left) {
        findModeHelperApproach1(root->left);
    }

    if(root->right) {
        findModeHelperApproach1(root->right);
    }
}   

vector<int> findModeApproach1(TreeNode* root) {
    vector<int> answer;
    findModeHelperApproach1(root);
    int max = nodeOccurence.begin()->second;
    for(auto i = nodeOccurence.begin(); i != nodeOccurence.end(); i++) {
        if(i->second > max) {
            max = i->second;
        }
    }

    for(auto i = nodeOccurence.begin(); i != nodeOccurence.end(); i++) {
        if(i->second == max) {
            answer.push_back(i->first);
        }
    }

    return answer;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------////////////

vector<int> answer;
int freq = 0; TreeNode* prevNode = nullptr; int maxVal = 0;

void findModeHelperApproach2(TreeNode* root) {
    if(root->left) {
        findModeHelperApproach2(root->left);
    }

    if(prevNode && prevNode->val == root->val) {
        freq += 1;
    } else {
        // This is the start of a new Node...
        if(freq > maxVal) { // This freq is freq of the previous node...
            maxVal = freq;
            vector<int> newAnswer = {prevNode->val};
            answer = newAnswer;
        } else if(freq == maxVal && freq != 0) {
            answer.push_back(prevNode->val);
        }

        freq = 1;
    }

    prevNode = root;

    if(root->right) {
        findModeHelperApproach2(root->right);
    }
}

vector<int> findModeApproach2(TreeNode* root) {
    if(!root->left && !root->right) {
        vector<int> newAnswer = {root->val};
        answer = newAnswer;
        return answer;
    }

    findModeHelperApproach2(root);

    if(freq > maxVal) {
        vector<int> newAnswer = {prevNode->val};
        answer = newAnswer;
    } else if(freq == maxVal) {
        answer.push_back(prevNode->val);
    }

    return answer;
}

int main () {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}