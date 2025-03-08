class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=INT_MAX;

        for(int i=0;i<blocks.length();i++){
            int turns=0;
            int j=i;
            while(j<blocks.length() && j-i+1<=k){
                if(blocks[j]=='B'){
                    turns++;
                }
                j++;
            }

            count=min(count,k-turns);
        }
        return count;
    }
};