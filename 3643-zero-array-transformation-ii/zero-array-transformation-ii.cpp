class Solution {
public:

    bool DiffArray(vector<int>&nums,vector<vector<int>>&queries,int k){

        int n=nums.size();
        vector<int>diffArray(n,0);

        for(int i=0;i<=k;i++){
            int start = queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            diffArray[start]+=val;
            if(end+1<n)
                diffArray[end+1]-=val;

        }

        int sum=0;

        for(int i=0;i<n;i++){
            sum+=diffArray[i];

            diffArray[i]=sum;

            if(nums[i]-diffArray[i]>0)
                return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

     int Q = queries.size();

     long long sum = accumulate(nums.begin(),nums.end(),0LL);

     if(sum==0) return 0;

     int l=0;
     int r=Q-1;
     int result=-1;

     while(l<=r){
        int mid=l+(r-l)/2;

        if(DiffArray(nums,queries,mid)){
            result=mid+1;
            r=mid-1;
        }else{
            l=mid+1;
        }
     }
     return result;   
    }
};