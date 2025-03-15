class Solution {
public:
    bool isPossible(vector<int>nums,int capability,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=capability){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=INT_MAX;
        int r=INT_MIN;
        for(int i:nums){
            if(i<l){
                l=i;
            }
            if(i>r){
                r=i;
            }
        }
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};