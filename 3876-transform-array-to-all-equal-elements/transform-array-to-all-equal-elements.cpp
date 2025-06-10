class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>minus1 = nums;
        
        vector<int>plus1 =nums;

        int op1=0,op2 = 0;
        for(int i=0;i<n-1;i++){
            if(minus1[i]==1){
                minus1[i]=minus1[i]*-1;
                minus1[i+1]=minus1[i+1]*-1;
                op1++;
            }
        }

        for(int i=0;i<n-1;i++){
            if(plus1[i]==-1){
                plus1[i]=plus1[i]*-1;
                plus1[i+1]=plus1[i+1]*-1;
                op2++;
            }
        }

        if(plus1[n-1]!=1) op2=1e9;
        if(minus1[n-1]!=-1) op1=1e9;
        
        return min(op1,op2)<=k;
    }
};