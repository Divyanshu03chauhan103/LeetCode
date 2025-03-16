class Solution {
public:
    bool isPossible(long long min, vector<int>& ranks,int cars){

        long long count=0;
        for(int i:ranks){

            count +=sqrt(min/i);
            if(count>=cars) return true;
        }
       
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        
        int min = *min_element(ranks.begin(),ranks.end());
        long long high= (long long)min*cars*cars;
        long long low=0;
        long long ans=-1;
       while(low<=high){
            long long mid=low+(high-low)/2;

            if(isPossible(mid,ranks,cars)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    
        
    }
};