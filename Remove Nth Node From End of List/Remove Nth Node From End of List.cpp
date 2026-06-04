// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //NeetCode solution: two pointers
        /*ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;*/
        
        ListNode* current = head;
        //Count the length of the list
        int length = 1;
        while(current->next){
            current = current->next;
            length++;
        }
        //Calculate the node that needs to be removed
        int target = length - n + 1;
        //Remove the target
        current = head;
        for(int i = 1 ; i < target - 1 ; i++){
            current = current->next;
        }
        //Handle removing the first node (head)
        if(length == n){
            head = head->next;
        }
        else{
            ListNode* temp = current->next;
            current->next = temp->next;
        }
        return head;
    }
};
