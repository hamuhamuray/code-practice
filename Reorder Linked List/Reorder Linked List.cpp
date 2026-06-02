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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        //Count the length of the list
        int n = 0;
        while(curr){
            n++;
            curr = curr->next;
        }
        //Handle empty list
        if(n != 0){
            //Find the half of the list, then reverse the rest of the list
            curr = head;
            for(int i = 0 ; i < n / 2 ; i++){
                curr = curr->next;
            }
            //Another way to find the middle of the list
            // ListNode* slow = head;
            // ListNode* fast = head->next;
            // while (fast != nullptr && fast->next != nullptr) {
            //     slow = slow->next;
            //     fast = fast->next->next;
            // }

            ListNode* prev = curr;
            ListNode* temp1;
            curr = curr->next;
            prev->next = nullptr;
            while(curr){
                temp1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp1;
            }
            //Reorder the list from the head and the tail
            ListNode* tail = prev;
            ListNode* temp2;
            curr = head;
            while(tail->next){
                temp1 = curr->next;
                curr->next = tail;
                temp2 = tail->next;
                tail->next = temp1;
                //Update
                curr = temp1;
                tail = temp2;
            }
        }
    }
};
