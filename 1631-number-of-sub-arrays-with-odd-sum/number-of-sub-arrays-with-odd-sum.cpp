class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        
        int result=0;
        int sum=0;
        int evenCount=1;
        int oddCount=0;
        for(int i=0 ;i < arr.size();i++){
            sum+=arr[i];
            if(sum%2 == 0){
                evenCount++;
                result= (result + oddCount)%mod;
            }
            else{
                result=(evenCount+result)%mod;
                oddCount++;
            }
        }
        return result;
    }
};

//Approach 1:
/*
 int numOfSubarrays(vector<int>& arr) {
        
        int result=0;
        vector<int>prefix(arr.size(),0);
        prefix[0] = arr[0];

        for(int i=1;i<arr.size();i++){
            
            prefix[i] = prefix[i-1] +arr[i];
        }

        int evenCount=1;
        int oddCount=0;
        for(int i:prefix){
            if(i%2 == 0){
                evenCount++;
                result= (result + oddCount)%mod;
            }
            else{
                result=(evenCount+result)%mod;
                oddCount++;
            }
        }
        return result;
    }
};
*/
