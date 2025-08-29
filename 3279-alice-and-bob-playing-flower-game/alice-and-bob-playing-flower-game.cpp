class Solution {
public:
    long long flowerGame(int n, int m) {
        long long result=0;
        int even_num = m/2;
        int odd_num = (m&1)==1?m/2+1:m/2;
        for(int i=1;i<=n;i++){

            if(i&1){
                result+=even_num;
            }else result+=odd_num;
        }
        return result;
    }
};