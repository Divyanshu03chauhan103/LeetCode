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
    ListNode* reverse(ListNode* head){

        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr){

            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(!head && !head->next) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){

            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* newHead=reverse(slow->next);

        ListNode* second=newHead;
        slow=head;

        while(second){
            if(second->val!=slow->val){
                reverse(newHead);
                return false;
            }
            second=second->next;
            slow=slow->next;
        }
        reverse(newHead);
        return true;

    }
};