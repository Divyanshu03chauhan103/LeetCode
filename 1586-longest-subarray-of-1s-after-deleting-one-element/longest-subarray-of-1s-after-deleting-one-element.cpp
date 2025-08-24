class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==1){
                count++;
            }else{
                count=0;
            }
            prefix[i]=count;
        }
        count=0;
        for(int i=n-2;i>=0;i--){

            if(nums[i+1]==1){
                count++;
            }else{
                count=0;
            }
            suffix[i]=count;
        }
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                result=max(prefix[i]+suffix[i]+1,result);
            else{
                result=max(prefix[i]+suffix[i],result);
            }
        }
        
        return result==n?result-1:result;
    }
};