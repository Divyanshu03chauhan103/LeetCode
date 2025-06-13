class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int>curr(n+1,0),after(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int lastIndex=ind;lastIndex>=-1;lastIndex--){
                 int len=after[lastIndex+1];

                if(lastIndex==-1||nums[ind]>nums[lastIndex])
                    len=max(len,1+after[ind+1]);

                 curr[lastIndex+1]=len;
            }
            after=curr;
        }
        return curr[0];
    }
};