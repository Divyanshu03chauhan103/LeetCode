class Solution {
public:
    bool is_Sorted(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    pair<int,int> min_sum_pos(vector<int>&nums){
        int n=nums.size();
        int min_sum=1e9;
        int pos=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]<min_sum){
                min_sum=nums[i]+nums[i+1];
                pos=i;
            }
        }
        return make_pair(pos,min_sum);
    }

    void merge_pair(vector<int>&nums,pair<int,int>p){
        int pos=p.first;
        int min_sum=p.second;

        nums[pos]=min_sum;
        nums.erase(nums.begin()+pos+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        
        int result=0;

        int n=nums.size();
        while(!is_Sorted(nums)){
            merge_pair(nums,min_sum_pos(nums));
            result+=1;
        }
        return result;
    }
};