class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans=0;
        int length=0;
        int max_val;

        for(int i:nums){

            if(i>max_val){

                max_val=i;
                length=1;
                ans=1;
            }
            else if(i==max_val){

                length++;
                ans=max(ans,length);
            }
            else length=0;
        }

        return ans;
    }
};