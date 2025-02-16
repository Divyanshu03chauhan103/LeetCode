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
    int count(ListNode* head){
        int result=0;
        ListNode* temp=head;
        while(temp){
            result++;
            temp=temp->next;
        }
        return result;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       
        if(!head || !head->next ) return head;
       
         int len = count(head);
         k = k % len; 
          int break_point =len- k;
         if(k==0) return head;
        
        ListNode* temp =head;
        ListNode* prev =NULL;
        while(break_point-- ){
            prev=temp;
            temp=temp->next;
        }

        if(prev) prev->next = nullptr;
        ListNode* new_head= temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next= head;

        return new_head;
    }
};

