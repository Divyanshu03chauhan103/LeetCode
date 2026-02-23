public class Solution {
    public bool IsDigitorialPermutation(int n) {
        
        int []fact = new int[10];
        fact[0]=fact[1]= 1;
        for(int i=2;i<10;i++){
            fact[i]=fact[i-1] * i;
        }
        int N=n;
        int digitorial=0;
        while(N>0){
            digitorial+=fact[N%10];
            N/=10;
        }
        int []freq = new int[10];
        while(digitorial>0){
            freq[digitorial%10]++;
            digitorial/=10;
        }
        while(n>0){
            int digit=n%10;
            if(freq[digit]==0) return false;
            freq[digit]--;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(freq[i]!=0) return false;
        }
        return true;

    }
}