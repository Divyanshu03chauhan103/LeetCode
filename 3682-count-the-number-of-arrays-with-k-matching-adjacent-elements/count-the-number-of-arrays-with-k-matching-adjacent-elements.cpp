const int mod=1e9+7;
class Solution {
public:
    long long findPow(long long a,long long b){
        if(b==0) return 1;
        long long half= findPow(a,b/2);

        long long result= (half* half)%mod;
        if(b%2==1) 
            result=(result*a)%mod;
        return result;
    }
    int nCr(int n,int r,vector<long long>&fact,vector<long long>&ferm){
        
        return fact[n]*ferm[n-r]%mod*ferm[r]%mod;
    }
    int countGoodArrays(int n, int m, int k) {
        
        vector<long long>factorial(n+1,1);
        vector<long long>fermat(n+1,1);
        for(int i=2;i<=n;i++){
            factorial[i]=(factorial[i-1]*i)%mod;
        }
        for(int i=0;i<=n;i++){
            fermat[i]=findPow(factorial[i],mod-2);
        }
        long long result=nCr(n-1,k,factorial,fermat);
        result=(result*m)%mod;
        result=(result*findPow(m-1,n-k-1))%mod;
        return result;
    }
};