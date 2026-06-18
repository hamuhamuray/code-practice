#include <unordered_map>
using namespace std;

class LRUCache {
private:
    //Definition of Node
    struct Node{
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v, Node *nt, Node *pv) : key(k), value(v), next(nt), prev(pv) {};
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    //Initailization
    LRUCache(int capacity) : capacity(capacity) {    
    }
    
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        else{
            //Move the recently used Node to head if Node isn't head, and update tail if needed;
            if(cache[key] != head){
                cache[key]->prev->next = cache[key]->next;
                //If cache[key] != tail, maintain prev of the next node of cache[key]; if cache[key] == tail, tail needs to be updated
                if(cache[key] != tail)cache[key]->next->prev = cache[key]->prev;
                else tail = cache[key]->prev;
                cache[key]->prev = nullptr;
                cache[key]->next = head;
                head->prev = cache[key];
                head = cache[key];
                head = cache[key];
            }
            return cache[key]->value;
        }
    }
    
    void put(int key, int value) {
        //Update the value of the key if the key exists
        if(cache.count(key)){
            cache[key]->value = value;
            //Move the recently used Node to head if Node isn't head, and update tail if needed;
            if(cache[key] != head){
                cache[key]->prev->next = cache[key]->next;
                //If cache[key] != tail, maintain prev of the next node of cache[key]; if cache[key] == tail, tail needs to be updated
                if(cache[key] != tail)cache[key]->next->prev = cache[key]->prev;
                else tail = cache[key]->prev;
                cache[key]->prev = nullptr;
                cache[key]->next = head;
                head->prev = cache[key];
                head = cache[key];
            }
        }
        else{
            //Add the key-value pair to the cache
            Node *newNode = new Node(key, value, head, nullptr);
            cache[key] = newNode;
            //Update head and tail
            if(!head)tail = newNode;
            else head->prev = newNode;
            head = newNode;
            //If the cache exceeds its capacity, remove the tail of the node;
            if(cache.size() > capacity){
                cache.erase(tail->key);
                Node *temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
    }
};

//NeetCode solution: list (doubly linked-list)
/*
class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
*/
