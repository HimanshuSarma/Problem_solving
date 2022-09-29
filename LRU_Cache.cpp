#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    // Pointer to an unordered_map...
    unordered_map<int, Node*>* cacheMap = nullptr;
    int cache_size = 0;
    int capacity = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    LRUCache(int capacity) {
        this->cacheMap = new unordered_map<int, Node*>[capacity];
        this->cache_size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = this->cacheMap->find(key);
        // cout<<it->second->key<<endl;
        if(it == this->cacheMap->end()) {
            // Given key was not found in the LRU Cache, so we have to insert it...
            return -1;
        } else {
            // Given key was found in the LRU Cache, so just return it's value...
            if(it->second == this->head && this->head != this->tail) {
                Node* keyNode = this->head;
                this->head = this->head->next;
                this->head->prev = nullptr;
                this->tail->next = keyNode;
                keyNode->prev = this->tail;
                this->tail = keyNode;
                keyNode->next = nullptr;
            } else if(it->second != this->head && it->second != this->tail) {
                it->second->prev->next = it->second->next;
                it->second->next->prev = it->second->prev;
                this->tail->next = it->second;
                it->second->prev = this->tail;
                it->second->next = nullptr;
                this->tail = it->second;
            }

            return it->second->val;
        }
    }
    
    void put(int key, int value) {
        auto it = cacheMap->find(key);
        if(it != this->cacheMap->end()) {
            it->second->val = value;
            if(it->second == this->head && this->head != this->tail) {
                Node* keyNode = this->head;
                this->head = this->head->next;
                this->head->prev = nullptr;
                this->tail->next = keyNode;
                keyNode->prev = this->tail;
                this->tail = keyNode;
            } else if(it->second != this->head && it->second != this->tail) {
                it->second->prev->next = it->second->next;
                it->second->next->prev = it->second->prev;
                this->tail->next = it->second;
                it->second->prev = this->tail;
                it->second->next = nullptr;
                this->tail = it->second;
            }
        } else {
            Node* newNode = new Node(key, value);
            if(!this->head) {
                this->head = newNode;
                this->tail = newNode;
                this->cacheMap->insert({key, newNode});

            } else {
                newNode->prev = this->tail;
                this->tail->next = newNode;
                this->tail = newNode;
                int LRUKey = this->head->key;
                if(this->cache_size + 1 > this->capacity) {
                    this->head = this->head->next;
                    this->head->prev = nullptr;
                    this->cacheMap->erase(LRUKey);
                }
                this->cacheMap->insert({key, newNode});
            }

            this->cache_size++;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(2,1);
    cache.put(1,1);
    cache.put(2,3);
    cache.put(4,1);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
}