class Solution {
public:
/*Approach 1:
    bool check(string sq,int num,int i,int curr_sum){
        if(i==sq.length()){
            return curr_sum==num;
        }
        if(curr_sum>num) return false;

        bool isPossible=false;
        for(int j=i;j<sq.length();j++){

            string curr_num = sq.substr(i,j-i+1);
            int val = stoi(curr_num);

            isPossible=  isPossible || check(sq,num,j+1,curr_sum+val);
            if(isPossible) return true;
        }
        return false;
    }
*/
    bool check(int sq_num,int curr_sum,int num){

        if(sq_num ==0 ){
            return curr_sum==num;
        }

        if(curr_sum>num) return false;

        return check( sq_num/10,curr_sum+sq_num%10,num)||
        check( sq_num/100,curr_sum+sq_num%100,num)||
        check( sq_num/1000,curr_sum+sq_num%1000,num)||
        check( sq_num/10000,curr_sum+sq_num%10000,num);
    }
    int punishmentNumber(int n) {
        
        int result=0;
        for(int i=1;i<=n;i++){

            int sq_num=i*i;
            // string sq = to_string(sq_num);
            // if(check(sq,i,0,0)){ // need to generate all the possible substring and calculate which one is correct
            //     result = result +sq_num;
            // }
            if(check(sq_num,0,i))
                result+=sq_num;
        }
        return result;
    }
};