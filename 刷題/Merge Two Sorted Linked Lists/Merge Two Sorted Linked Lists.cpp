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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Handle empty lists
        if(list1 == nullptr)return list2;
        else if(list2 == nullptr)return list1;

        //Merge the two lists by comparing the values
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head;
        ListNode* curr;
        //Start of the list
        if(curr1->val <= curr2->val){
            head = curr1;
            curr = curr1;
            curr1 = curr1->next;
        }
        else{
            head = curr2;
            curr = curr2;
            curr2 = curr2->next;
        }
        //Compare the value of the two lists, then merge
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->val <= curr2->val){
                curr->next = curr1;
                curr = curr->next;
                curr1 = curr1->next;
            }
            else{
                curr->next = curr2;
                curr = curr->next;
                curr2 = curr2->next;
            }
        }
        //Handle the rest of the list when the other list is empty
        if(curr1 == nullptr)curr->next = curr2;
        else curr->next = curr1;
        
        return head;
    }
};
