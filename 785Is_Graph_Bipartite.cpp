// TC: O(V+E)
// SC: O(V)

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int vertex = -1;
    int level = -1;
    int visitedFrom = -1;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int vertex, int level, int visitedFrom) {
        this->vertex = vertex;
        this->level = level;
        this->visitedFrom = visitedFrom;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Queue {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void enqueue(int vertex, int level, int visitedFrom) {
        Node* newNode = new Node(vertex, level, visitedFrom);
        if (head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }

        return;
    }

    Node* dequeue() {
        if (head == nullptr) return nullptr;
        Node* returnNode = new Node(tail->vertex, tail->level, tail->visitedFrom);
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
        return returnNode;
    }

    bool isEmpty() {
        return (head == nullptr);
    }
};

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> visited_level(graph.size(), -1);
    visited_level[0] = 0;

    Queue queue;
    queue.enqueue(0, 0, 0);

    Node* currentVertex = nullptr;

    for (int i = 0; i < graph.size(); i++) {
        if (visited_level[i] == -1) {
            if (queue.isEmpty()) {
                queue.enqueue(i, 0, 0);
            }

            while (!queue.isEmpty()) {
                currentVertex = queue.dequeue();
                for (int j = 0; j < graph[currentVertex->vertex].size(); j++) {
                    if (visited_level[graph[currentVertex->vertex][j]] != -1 && 
                        currentVertex->visitedFrom != graph[currentVertex->vertex][j] &&
                        visited_level[graph[currentVertex->vertex][j]] != currentVertex->level + 1 &&
                        visited_level[graph[currentVertex->vertex][j]] + 1 != currentVertex->level) {
                        return false;
                    } else if (currentVertex->visitedFrom != graph[currentVertex->vertex][j] && 
                        visited_level[graph[currentVertex->vertex][j]] == -1) {
                        queue.enqueue(graph[currentVertex->vertex][j], currentVertex->level + 1, currentVertex->vertex);
                        visited_level[graph[currentVertex->vertex][j]] = currentVertex->level + 1;
                    }
                }
            }
        }
    }

    return true;
}

int main () {
    vector<vector<int>> graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    isBipartite(graph);
}