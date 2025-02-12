class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&result,int idx,vector<int>&temp){

        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums,result,idx+1,temp);
        temp.pop_back();
        solve(nums,result,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int>curr;
        solve(nums,result,0,curr);

        return result;
    }
};