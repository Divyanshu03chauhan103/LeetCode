class Solution {
public:
int mod=1000000007;

    long power(int x,long i){

        if(i==0) return 1;

        long a=power(x,i/2 );

        if(i%2==0) return (a*a)%mod;
        else return (a*a*x)%mod;
    }

    int countGoodNumbers(long long n) {
        
        long even=(n+1)/2;
        long odd=n/2;
        
        long first=power(5,even)%mod;
        long second=power(4,odd)%mod;

        return (int)((first*second)%mod);
    }
};