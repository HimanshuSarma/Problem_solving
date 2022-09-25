#include <bits/stdc++.h>

using namespace std;

struct Node{
int data;
Node* left;
Node* right;
};

stack<Node*> nodeStack;

vector<int> topView(Node *root) {
    vector<int> ans;
    Node* currentNode = root;
    while(currentNode) {
        nodeStack.push(currentNode);
        currentNode = currentNode->left;
    }

    while(!nodeStack.empty()) {
        currentNode = nodeStack.top();
        nodeStack.pop();
        ans.push_back(currentNode->data);
    }

    if(currentNode->right) {
        currentNode = currentNode->right;
        while(currentNode) {
            ans.push_back(currentNode->data);
            currentNode = currentNode->right;
        }
    } 

    return ans;
}

int main() {
    
}