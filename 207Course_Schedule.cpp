// Time complexity: O(V+E).
// Space complexity: O(V+E)

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next = nullptr;
    Node (int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class List {
public: 
    Node* head = nullptr;
    bool result = false;
};

class AdjacencyList {
public:
    List* courses = nullptr;
    AdjacencyList(int x) {
        courses = new List[x];
    }

    void insertAdjacentVertex(int idx, int val) {
        Node* newNode = new Node(val);
        newNode->next = courses[idx].head;
        courses[idx].head = newNode;
    }
};


void buildGraph(int numCourses, vector<vector<int>>& prerequisites, AdjacencyList* graph) {
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < prerequisites.size(); j++) {
            if (prerequisites[j][0] == i) {
                graph->insertAdjacentVertex(i, prerequisites[j][1]);
            }
        }
    }
}

bool dfs(AdjacencyList* graph, vector<bool>& visited, int currentVertex, int numCourses) {

    if (visited[currentVertex]) return false;

    visited[currentVertex] = true;

    Node* trav = graph->courses[currentVertex].head;

    bool allPresMet = true;

    while(trav != nullptr) {
        if (trav->val == currentVertex) return false;
        else if (!visited[trav->val])
            allPresMet = dfs(graph, visited, trav->val, numCourses);
        else if (visited[trav->val] && !graph->courses[trav->val].result) return false;

        if (!allPresMet) {
            graph->courses[currentVertex].result = false;
            return false;    
        } 

        trav = trav->next;
    }

    graph->courses[currentVertex].result = allPresMet;
    return allPresMet;    
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    AdjacencyList* graph = new AdjacencyList(numCourses);
    buildGraph(numCourses, prerequisites, graph);  
    vector<bool> visited(numCourses, false);

    // Node* trav = nullptr;
    // for(int i = 0; i < numCourses; i++) {
    //     trav = graph->courses[i].head;
    //     while(trav != nullptr) {
    //         cout<<trav->val<<" ";
    //         trav = trav->next;
    //     }

    //     cout<<endl;
    // }

    bool ans = true;
 
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            ans = dfs(graph, visited, i, numCourses);
            if (!ans) {
                return false;
            } 
        }
    }

    return true;
}

int main () {
    vector<vector<int>> prerequisites = {{1,0}};
    canFinish(2, prerequisites);
}