class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ways=0;
        
        for(int i=0;i<=min(n,limit);i++){

            for(int j=0;j<=min(limit,n-i);j++){

                int ch3 = min(limit,n-i-j);
                if(ch3+i+j==n) ways++;
            }
        }
        return ways;
    }
};