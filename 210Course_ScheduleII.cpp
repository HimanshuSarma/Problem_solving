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

bool dfs(AdjacencyList* graph, vector<bool>& visited, int currentVertex, int numCourses, vector<int>& ans) {

    if (visited[currentVertex]) return false;

    visited[currentVertex] = true;

    Node* trav = graph->courses[currentVertex].head;

    bool allPresMet = true;

    while(trav != nullptr) {
        if (trav->val == currentVertex) return false;
        else if (!visited[trav->val])
            allPresMet = dfs(graph, visited, trav->val, numCourses, ans);
        else if (visited[trav->val] && !graph->courses[trav->val].result) return false;

        if (!allPresMet) {
            graph->courses[currentVertex].result = false;
            return false;    
        } 

        trav = trav->next;
    }

    graph->courses[currentVertex].result = allPresMet;
    ans.push_back(currentVertex);
    return allPresMet;    
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    AdjacencyList* graph = new AdjacencyList(numCourses);
    buildGraph(numCourses, prerequisites, graph);  
    vector<bool> visited(numCourses, false);

    vector<int> ans = {};

    bool result = true;
 
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            result = dfs(graph, visited, i, numCourses, ans);
            if (!result) {
                vector<int> emptyAns = {};
                return emptyAns;
            } 
        }
    }

    return ans;
}

int main () {
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    findOrder(4, prerequisites);
}



