class Solution {
public:
    bool check(int col,int row,vector<string>&strs){

        for(int i=0;i<row-1;i++){
            if(strs[i][col]>strs[i+1][col]) return false;
        }

        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        
        int result=0;
        int n=strs.size();
        int m=strs[0].length();

        for(int i=0;i<m;i++){
            if(!check(i,n,strs)) result++;
        }

        return result;
    }
};