class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        int result=0;
        int prev=-1;
        for(int i:nums){
            if(prev<=i){
                result++;
                prev=i;
            }
        }   
        return result;
    }
};
