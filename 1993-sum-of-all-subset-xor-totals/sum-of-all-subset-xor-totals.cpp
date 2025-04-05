class Solution {
public:
    void solve(vector<vector<int>>&arr,vector<int>&nums,int i,vector<int>&curr){

        if(i==nums.size()){
            arr.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(arr,nums,i+1,curr);
        curr.pop_back();

        solve(arr,nums,i+1,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subsets;
        vector<int>curr;
        solve(subsets,nums,0,curr);
        int result=0;
        for(auto i:subsets){
            if(i.empty()) continue;
            int curr=i[0];
            for(int j=1;j<i.size();j++){
                curr=curr^i[j];
            }
            result+=curr;
        }

        return result;
    }
};