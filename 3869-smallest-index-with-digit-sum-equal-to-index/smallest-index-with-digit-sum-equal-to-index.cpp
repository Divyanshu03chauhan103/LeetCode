class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ind=0;
        for(auto i:nums){

            int num=i;
            int sum=0;
            while(num){
                sum =sum+num%10;
                num/=10;
            }
            if(ind==sum) return ind;
            
            ind++;
        }
        return -1;
    }
};