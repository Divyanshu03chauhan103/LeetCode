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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* temp=nullptr;
        return solve(temp,head);
    }

    ListNode* solve(ListNode* temp,ListNode* head){

        if(!head) return temp;
        ListNode* next= head->next;
        head->next=temp;
       
        return  solve(head,next);
    }
};