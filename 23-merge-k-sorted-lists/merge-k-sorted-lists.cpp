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
     ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* headu = dummy;
        ListNode* temp1 = left;
        ListNode* temp2 = right;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                
                 headu->next = temp1;
                temp1 = temp1->next;
              


            }
            else {
           
                headu->next = temp2;
                temp2 = temp2->next;
                
            }
              headu = headu->next;
            
            
        }
        while(temp1){
            headu->next = temp1;
            temp1 = temp1->next;
            headu = headu->next;
        }
        while(temp2){
            headu->next = temp2;
            temp2 = temp2->next;
            headu = headu->next;
        }
        return dummy->next;


      
        

     }
    ListNode* mergesort(vector<ListNode*>& lists,int low,int high){
        if(low > high) return NULL;
         
     if(low == high) return lists[low];
    int mid = low +(high-low)/2;

     ListNode* left =  mergesort( lists,low,mid);
     ListNode* right = mergesort(lists,mid+1,high);
     return merge(left,right);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        

        if(lists.empty()) return NULL; 

        return mergesort(lists,0,lists.size()-1);

    }
};