class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int result=1;

        int i=1;
        int n =ratings.size();
        while(i<ratings.size()){

            if(ratings[i]==ratings[i-1]){
                result++;
                i++;
                continue;
            }
            int peek=1;    
            while(i<n && ratings[i]>ratings[i-1]){
             
             peek++;
             result+= peek;
             i++;
            }

            int down =1;
            while(i<n && ratings[i]<ratings[i-1]){
                result+=down;
                down++;
                i++;
            }

            if(down>peek){
                result+=down-peek;
            }
        }

        return result;
    }
};