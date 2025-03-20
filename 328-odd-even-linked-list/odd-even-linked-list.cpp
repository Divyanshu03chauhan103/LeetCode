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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* dNode1 = new ListNode();

        ListNode* DNode2 = new ListNode();

        ListNode* temp=head;;
        ListNode* temp1=dNode1;
        ListNode* temp2=DNode2;
        int index=1;
        while(temp){
            
            if((index)%2==0){
                temp1->next=temp;
                temp1=temp1->next;
            }else{
                temp2->next=temp;
                temp2=temp2->next;
            }
            temp=temp->next;
            index++;
        }
        temp1->next=nullptr;
        temp2->next=dNode1->next;

        return DNode2->next;
    }
};