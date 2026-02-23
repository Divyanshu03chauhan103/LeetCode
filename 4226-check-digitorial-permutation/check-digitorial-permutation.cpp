class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int>fact(10,0);

        fact[0]=fact[1]=1;

        for(int i=2;i<10;i++){
            fact[i]=fact[i-1]*i;
        }

        int N=n;
        int digitorial=0;
        while(N){
            digitorial+=fact[N%10];
            N=N/10;
        }
        vector<int>freq(10,0);
        
        while(digitorial){
            freq[digitorial%10]++;
            digitorial/=10;
        }
        while(n){
            if(freq[n%10]==0) return false;
            freq[n%10]--;
            n=n/10;
        }
        for(int i = 0; i < 10; i++){
                if(freq[i] != 0) return false;
            }
        return true;
    }
};