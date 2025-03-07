class Solution {
public:
    void isPrime(vector<int>&result,int left,int right){

        vector<bool>check(1000001,true);

        for(int i=2;i<=right;i++){
            
            if(check[i]){
                if(i>=left)
                    result.push_back(i);
                for(int j=i*2;j<=right;j=j+i){
                    check[j]=false;
                }
            }
        }

    }


    vector<int> closestPrimes(int left, int right) {
        
        vector<int>result;
        isPrime(result,left,right);
        int num1=-1;
        int num2=-1;
        int diff=INT_MAX;
        for(int i=1;i<result.size();i++){

            if(result[i]-result[i-1]<diff){
                diff=result[i]-result[i-1];
                num1=result[i-1];
                num2=result[i];
            }
            else if(result[i]-result[i-1]==diff){
                if(num1>result[i-1]){
                    num1=result[i-1];
                    num2=result[i];
                }
            }
        }

        return {num1,num2};
    }
};