class Solution {
public:
    int tribonacci(int n) {
        int a=0;
        if(n==0) return 0;
        if(n<=2) return 1;
        int b=1;
       int c=1;

        for(int i=3;i<=n;i++){
            int sum=a+b+c;
            a=b;
            b=c;
            c=sum;
        }
        return c;
    }
};