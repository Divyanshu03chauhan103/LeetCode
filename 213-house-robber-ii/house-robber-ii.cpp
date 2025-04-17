class Solution {
public:
    int rob(vector<int>& nums) {
    
         if(nums.size()==1) return nums[nums.size()-1];
         int prev=nums[0];
         int prev2=0;
         
         for(int i=1;i<nums.size()-1;i++){

            int take=nums[i]+prev2;
            

            int non_take=prev;
            int curr=max(take,non_take);

            prev2=prev;
            prev=curr;
         }
         
          prev2=nums[1];
         int prev3=0;
         
         for(int i=2;i<nums.size();i++){

            int take=nums[i]+prev3;
            

            int non_take=prev2;
            int curr=max(take,non_take);

            prev3=prev2;
            prev2=curr;
         }
      
         return max(prev,prev2);
    }
};