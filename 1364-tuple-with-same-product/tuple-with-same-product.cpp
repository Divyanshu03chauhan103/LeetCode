class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

               

                mp[nums[i]*nums[j]]++;
            }
        }
        int pairs=0;
        for(auto [key,value]:mp){
            int curr_value=0;
            if(value>=2){
                curr_value=value;
                
                pairs+=(curr_value-1)*(curr_value)/2;
                
                
            }
                
        }

        int result=8*pairs;

        return result;
    }
};