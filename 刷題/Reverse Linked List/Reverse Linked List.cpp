//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //NeetCode Solution: Recursion
        // if (!head) {
        //     return nullptr;
        // }

        // ListNode* newHead = head;
        // if (head->next) {
        //     newHead = reverseList(head->next);
        //     head->next->next = head;
        // }
        // head->next = nullptr;

        // return newHead;
        
        
        //Deal with empty head
        if(head == nullptr)return head;
        ListNode* current = head; 
        ListNode* next_node = head->next;
        ListNode* temp;
        while(current != nullptr && next_node != nullptr){
            //Access to the next node of next_node
            temp = next_node->next;
            //Change the next of next_node
            next_node->next = current;
            //Update
            current = next_node;
            next_node = temp;
        }
        //Set the original head as the tail
        head->next = nullptr;
        //Set the new head
        head = current;
        return head;
    }
};
