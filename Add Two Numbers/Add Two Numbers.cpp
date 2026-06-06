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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current_1 = l1;
        ListNode* current_2 = l2;
        ListNode* largest_digit;
        //Add the value in l1 to l2
        while(current_1 && current_2){
            current_2->val += current_1->val;
            //Check if val > 9, if true, carry 1 to the next node
            if(current_2->val > 9){
                current_2->val %= 10;
                if(current_2->next)current_2->next->val += 1;
                //Handle the case where l2 needs one more digit
                else{
                    ListNode* new_node = new ListNode(1);
                    current_2->next = new_node;
                }
            }
            //Update
            largest_digit = current_2;
            current_1 = current_1->next;
            current_2 = current_2->next;
        }
        //If current_2 = nullptr, connect l1 to the last node of l2 (largest_digit)
        if(!current_2)largest_digit->next = current_1;
        //If current_1 = nullptr, check if current_2 needs to carry 1 to the next digit
        else if(!current_1 && current_2){
            while(current_2->val > 9){
                current_2->val %= 10;
                if(current_2->next)current_2->next->val += 1;
                //Handle the case where l2 needs one more digit
                else{
                    ListNode* new_node = new ListNode(1);
                    current_2->next = new_node;
                }
            }
        }
        return l2;
    }
};
