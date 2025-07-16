class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int even=0;
        int odd=0;
        for(int i:nums){
            if(i%2==0){
                even++;
            }else
                odd++;
        }
        int parity=nums[0]%2;
        int alternating=1;
        for(int i=1;i<nums.size();i++){
            int curr_parity=nums[i]%2;
            if(parity!=curr_parity){
                alternating++;
                parity=curr_parity;
            }
        }
        return max({even,odd,alternating});
    }
};