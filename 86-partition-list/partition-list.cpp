/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode* head1 = new ListNode(0);
         ListNode* head2 = new ListNode(0);
         ListNode* low = head1;
         ListNode* high = head2;
        
        ListNode* temp = head;


        while(temp){
            if(temp->val<x){
                low->next = temp;
                low  = low->next;
            }
               

            else if(temp->val>=x){
                high->next = temp;
                high = high->next;


            }
            temp = temp->next;
        }
        high->next = NULL;
        low->next = head2->next;

        return head1->next;


        

    }
};