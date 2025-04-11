class Solution {
public:
    pair<vector<int>,int> countSum(int num){
        
        vector<int>prefix(5,0);
        
        int count=0;
        prefix[count]=num%10;
        num=num/10;
        count++;
        while(num){
            int n=num%10;
            prefix[count]=prefix[count-1]+n;
            count++;
            num=num/10;    
        }

        return {prefix,count};
    }
    int countSymmetricIntegers(int low, int high) {
        
        int result=0;
        for(int i=low;i<=high;i++){

            auto it = countSum(i);
            int count=it.second;
            vector<int>prefix=it.first;

            if(count%2==1) continue;

            int firstHalf= prefix[count/2-1];
            int secondHalf=prefix[count-1]-firstHalf;
            if(firstHalf==secondHalf) result++;
        }
        return result;
    }
};