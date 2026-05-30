//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool hasCycle(ListNode* head) {
        //NeetCodde solution: hash map
        /*unordered_set<ListNode*> seen;
        ListNode* cur = head;
        while (cur) {
            if (seen.find(cur) != seen.end()) {
                return true;
            }
            seen.insert(cur);
            cur = cur->next;
        }
        return false;*/
        
        //Traverse the nodes with one step (turtle) and two steps (hare), if the hare and the turtle are at the same node, it suggest that the cycle exists
        //Handle empty and one-node lists
        if(head == nullptr || head->next == nullptr)return false;
        ListNode* turtle = head->next;
        ListNode* hare = head->next->next;
        while(hare != nullptr && hare->next != nullptr){
            if(turtle == hare)return true;
            //Update
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return false;
    }
};
