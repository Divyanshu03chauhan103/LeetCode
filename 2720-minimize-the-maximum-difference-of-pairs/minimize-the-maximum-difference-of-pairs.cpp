class Solution {
public:
    int isPossible(vector<int>&nums,int p,int diff){

        int count =0;

        for(int i=0;i<nums.size()-1;i++){

            if(nums[i+1]-nums[i]<=diff){
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        int result =0;
        int n= nums.size();
        int high = nums[n-1]-nums[0];

        int low=0;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(isPossible(nums,p,mid)){

                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
};