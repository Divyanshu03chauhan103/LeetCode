class Solution {
public:
    bool isPossible(vector<int>arr,int k){
        if(abs(arr[2]-arr[0])>k) return false;
        return true;
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0;i<n-2;i=i+3){

            vector<int>temp(nums.begin()+i,nums.begin()+i+3);

            if(isPossible(temp,k))
                result.push_back(temp);
            else return {};
        }
        return result;
    }
};