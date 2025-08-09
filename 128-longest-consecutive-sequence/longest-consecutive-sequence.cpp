class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
       set<int>s(nums.begin(),nums.end());
       int n=nums.size();
        if(n==0) return 0;
        int result=1;
        int length=1;
       for(int i:s){

            if(s.count(i-1)){
                length++;
            }else{
                length=1;
            }
            result=max(length,result);
       }
       return result;
    }
};