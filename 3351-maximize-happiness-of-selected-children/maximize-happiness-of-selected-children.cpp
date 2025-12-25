class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end());

        int n=happiness.size();

        int dec=0;
        long long result=0;

        for(int i=n-1;i>=n-k;i--){
            happiness[i]-=dec;
            dec++;
            if(happiness[i]>=0)
                result+=happiness[i];
            else 
                break;
            
        }
        return result;
    }   
};