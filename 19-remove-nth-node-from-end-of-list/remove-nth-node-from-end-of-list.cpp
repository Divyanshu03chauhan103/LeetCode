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
        if(!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp){  // Fixed condition
            ListNode* after = temp->next;
            temp->next = prev;
            prev = temp;
            temp = after;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;

        // Step 1: Reverse the linked list
        ListNode* newHead = reverse(head);
        ListNode* temp = newHead;
        ListNode* prev = NULL;

        while(n-- && temp){
            if(n == 0){
                if(prev)
                    prev->next = temp->next;  
               else{
                newHead=newHead->next;
               }
               delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

      
        return reverse(newHead);
    }
};
