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

    ListNode* reverse(ListNode* prev,ListNode* head){

            if(!head ) return prev;

            ListNode* after=head->next;
            head->next=prev;
            prev=head;
            
            return reverse(prev,after);
    }
    ListNode* reverseList(ListNode* head) {
        
        

        return reverse(nullptr,head);


    }
};