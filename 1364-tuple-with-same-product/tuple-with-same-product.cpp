class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;

                mp[nums[i]*nums[j]]++;
            }
        }
        int pairs=0;
        for(auto [key,value]:mp){
            int curr_value=0;
            if(value>=4){
                curr_value=value/2;
                
                pairs+=(curr_value-1)*(curr_value)/2;
                
                
            }
                
        }

        int result=8*pairs;

        return result;

        result=2*result;

        return result;
    }
};