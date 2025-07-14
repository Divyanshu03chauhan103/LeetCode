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
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
            ListNode* after=temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        int result=0;
        head=reverse(head);

        int pow_count=0;
        while(head){
            if(head->val == 1) {
                result += pow(2, pow_count);
            }
            pow_count++;
            head=head->next;
        }
        return result;
    }
};