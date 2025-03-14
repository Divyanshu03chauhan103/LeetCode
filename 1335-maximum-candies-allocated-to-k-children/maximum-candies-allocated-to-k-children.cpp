class Solution {
public:
    bool canDivide(long long mid,long long k,vector<int>&candies){
        for(auto i:candies){
            int canHave=i/mid;
            k=k-canHave;
            if(k<=0) return true;
        }

        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long high=*max_element(candies.begin(),candies.end());

        long long low=1;
        long long result=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canDivide(mid,k,candies)){
                result=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return result;
    }
};