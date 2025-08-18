class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int final_result=start^goal;
        int count=0;

        for(int i=0;i<31;i++){
            if(final_result&(1<<i)) count++;
        }


        return count;
        
    }
};