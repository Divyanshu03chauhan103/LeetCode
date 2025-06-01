class Solution {
public:
    long long distributeCandies(int n, int limit) {
         long long ways=0;

        for(int i=max(0,n-2*limit);i<=min(n,limit);i++){

           int N=max(0,n-i);

           int mini = max(0,N-limit);
           int maxi= min(N,limit);
           ways+=(maxi-mini+1);
        }
        return ways;
    }
};