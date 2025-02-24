class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0;
        int i=0;
        int n=nums.size();
        int jump=0;
        while(j<n-1){
            int farthest=0;
            for(int k=i;k<=j;k++){

                farthest =max(farthest,nums[k]+k);
            }

            i=j+1;
            j=farthest;
            jump++;
        }
        return jump;
    }
};