// Approach 2(Iterative)...
// TC: If we do analysis considering the tree to be a complete binary tree, then, we will have 2 iterations
//     for almost half of the nodes and 1 iteration for the remaining half.
//     So, the TC is approximately 1.5N or if we take an upper bound, it'll be 2N.
//     So, time complexity = O(N).

// SC: The upper bound space complexity of the queue is N.
//     So, SC = O(N).
// Approach 2(Iterative)

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


// Approach 1 (recursive)...
// queue<TreeNode*> levelOrder;

// void zigzagLevelOrderHelper(TreeNode* root, vector<vector<int>>& ans, 
//     char currentLevel, int totalNodes) {

//     vector<int> currentLevelAns;
//     if(levelOrder.empty()) {
//         levelOrder.push(root);
//         currentLevelAns.push_back(root->val);
//         ans.push_back(currentLevelAns);
//         zigzagLevelOrderHelper(root, ans, currentLevel == 'l' ? 'r' : 'l', 1);
//     } else {
//         TreeNode* currentNode = nullptr;
//         for(int i = 0; i < totalNodes; i++) {
//             currentNode = levelOrder.front();
//             levelOrder.pop();
//             if(currentNode->left) {
//                 currentLevelAns.push_back(currentNode->left->val);
//                 levelOrder.push(currentNode->left);
//             } 

//             if(currentNode->right) {
//                 currentLevelAns.push_back(currentNode->right->val);
//                 levelOrder.push(currentNode->right);
//             } 
//         }

//         if(currentLevel == 'l') {
//             if(levelOrder.size() > 0) {
//                 ans.push_back(currentLevelAns);
//                 zigzagLevelOrderHelper(root, ans, currentLevel == 'l' ? 'r' : 'l', levelOrder.size());
//             }
//         } 
//         else {
//             int temp;
//             for(int i = 0; i < (currentLevelAns.size()/2); i++) {
//                 temp = currentLevelAns[i];
//                 currentLevelAns[i] = currentLevelAns[currentLevelAns.size()-1-i];
//                 currentLevelAns[currentLevelAns.size()-1-i] = temp;
//             }

//             if(levelOrder.size() > 0) {
//                 ans.push_back(currentLevelAns);
//                 zigzagLevelOrderHelper(root, ans, currentLevel == 'l' ? 'r' : 'l', levelOrder.size());
//             }    
//         }
//     }
// }

// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//     vector<vector<int>> ans;
//     if(!root) return ans;
//     zigzagLevelOrderHelper(root, ans, 'l', 0);
//     return ans;
// }
// Approach 1 (recursive)...

// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------

// Approach 2 (iterative)...
queue<TreeNode*> levelOrder;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    
    levelOrder.push(root);
    bool direction = true; // true is for l to r...
    while(!levelOrder.empty()) {
        int size = levelOrder.size();
        vector<int> currentLevelAns(size);
        TreeNode* currentNode = nullptr;
        for(int i = 0; i < size; i++) {
            currentNode = levelOrder.front();
            levelOrder.pop();
            currentLevelAns[i] = currentNode->val;

            if(currentNode->left) {
                levelOrder.push(currentNode->left);
            }

            if(currentNode->right) {
                levelOrder.push(currentNode->right);
            }
        }

        if(direction) {
            ans.push_back(currentLevelAns);
        } else {
            int temp;
            for(int i = 0; i < currentLevelAns.size()/2; i++) {
                temp = currentLevelAns[i];
                currentLevelAns[i] = currentLevelAns[currentLevelAns.size()-1-i];
                currentLevelAns[currentLevelAns.size()-1-i] = temp;
            }

            ans.push_back(currentLevelAns);
        }

        direction = direction ? false : true;
    }

    return ans;
}
// Approach 2 (iterative)...

int main() {
    
}