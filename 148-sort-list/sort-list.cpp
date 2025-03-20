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
    ListNode* sortList(ListNode* head) {
        if(!head ||!head->next) return head;
        vector<int>hash;
        ListNode* temp=head;
        while(temp){
            hash.push_back(temp->val);
            temp=temp->next;
        }

        sort(hash.begin(),hash.end());

        ListNode* dHead=new ListNode();
        temp=dHead;
        for(int i:hash){
            ListNode* newNode=new ListNode(i);
            temp->next=newNode;
            temp=temp->next;
        }
        return dHead->next;
    }
};