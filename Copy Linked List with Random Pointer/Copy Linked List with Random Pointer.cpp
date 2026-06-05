#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //NeetCode solution: one-pass
        /*unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            if (oldToCopy.find(cur) == oldToCopy.end()) {
                oldToCopy[cur] = new Node(0);
            }
            oldToCopy[cur]->val = cur->val;
            if (oldToCopy.find(cur->next) == oldToCopy.end()) {
                oldToCopy[cur->next] = new Node(0);
            }
            oldToCopy[cur]->next = oldToCopy[cur->next];
            if (oldToCopy.find(cur->random) == oldToCopy.end()) {
                oldToCopy[cur->random] = new Node(0);
            }
            oldToCopy[cur]->random = oldToCopy[cur->random];
            cur = cur->next;
        }
        return oldToCopy[head];*/

        //NeetCode Solution: O(1) extra space
        /*if (head == nullptr) {
            return nullptr;
        }

        Node* l1 = head;
        while (l1 != nullptr) {
            Node* l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }

        Node* newHead = head->next;

        l1 = head;
        while (l1 != nullptr) {
            if (l1->random != nullptr) {
                l1->next->random = l1->random->next;
            }
            l1 = l1->next->next;
        }

        l1 = head;
        while (l1 != nullptr) {
            Node* l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != nullptr) {
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }

        return newHead;*/
        
        //Handle empty list
        if(!head) return nullptr;
        //Create the hash map for origin node and copied node, and deal with val and next of the copied node
        unordered_map<Node*, Node*> mp;
        Node* current = head;
        Node* copied_head = nullptr;
        Node* prev = nullptr;
        while(current){
            Node* new_node = new Node(current->val);
            if(!copied_head) copied_head = new_node;
            mp[current] = new_node;
            if(prev)prev->next = new_node;
            prev = new_node;
            current = current->next;
        }
        //Deal with random of the copied node by looking up mp
        current = head;
        Node* copied_current = copied_head;
        while(current){
            copied_current->random = mp[current->random];
            current = current->next;
            copied_current = copied_current->next;
        }
        
        return copied_head;
    }
};