class Solution {
public:
    int findMin(vector<int>&tops,vector<int>&bottoms,int val){

        int top=0;
        int bottom=0;

        for(int i=0;i<tops.size();i++){
            if(tops[i]!=val && bottoms[i]!=val) return -1;
            else if(tops[i]!=val) top++;
            else if(bottoms[i]!=val)bottom++;
        }
        return min(top,bottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int result=INT_MAX;

        for(int i=1;i<7;i++){
            int val=findMin(tops,bottoms,i);
            if(val!=-1){
                result=min(result,val);
            }
        }
        return result==INT_MAX? -1 :result;
    }
};