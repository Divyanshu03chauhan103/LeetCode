class Solution {
public:
    long long coloredCells(int n) {
        
        if(n==1) return 1;

        long long result=1;
        long long curr_add=0;
        while(n>1){
            curr_add +=4;
            result += curr_add;
            n--;
        }
        return result;
    }
};