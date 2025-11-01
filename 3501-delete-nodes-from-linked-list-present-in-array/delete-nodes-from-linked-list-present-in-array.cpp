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
    // bool ispresent(int k,vector<int>& nums){

    //     for(int i:nums){

    //         if(i==k)
    //             return true;
    //     }
    //     return false;
    // }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* temp=head;

        ListNode* dnode = new ListNode();

        ListNode* temp2=dnode;

        unordered_set<int>st(nums.begin(),nums.end());


        while(temp){
            if(st.find(temp->val)==st.end()){

                temp2->next=temp;
                temp2=temp2->next;
            }
            temp=temp->next;
        }

            temp2->next=nullptr;
        return dnode->next;
    }
};