class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n= ratings.size();
        vector<int>left_ngbr(n),right_ngbr(n);
        left_ngbr[0]=1;
        int count=1;
        for(int i=1;i<n;i++){
            
            if(ratings[i]>ratings[i-1]){
                count++;
                left_ngbr[i]=count;
            }
            else{

                count=1;
                left_ngbr[i]=count;
            }
        }
            count=1;

            right_ngbr[n-1]=1;
         for(int i=n-2;i>=0;i--){
            
            if(ratings[i]>ratings[i+1]){
                count++;
                right_ngbr[i]=count;
            }
            else{

                count=1;
                right_ngbr[i]=count;
            }
        }

        int result=0;

        for(int i=0;i<n;i++){

            result+=max(left_ngbr[i],right_ngbr[i]);
        }

        return result;
    }
};