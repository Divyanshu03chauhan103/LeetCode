class Solution {
public:

    void solve(int target, long eval,long residual,string path, vector<string>& result, string num,int i){

        if(i==num.length()){
            if(eval == target)
                result.push_back(path);
            return ;
        }

        string curr;
        long currnum=0;
        for(int j=i;j<num.length();j++){

            if(j>i && num[i]=='0') return ;

            curr+=num[j];
            currnum = currnum*10 + num[j]-'0';

            if(i==0)
                solve(target,eval+currnum,currnum,path + curr , result,num,j+1);
            else{
                solve(target,eval+currnum,currnum,path +"+"+ curr , result,num,j+1);
                solve(target,eval-currnum,-currnum,path +"-"+ curr , result,num,j+1);
                solve(target,(eval-residual)+residual*currnum,residual*currnum,path +"*"+ curr , result,num,j+1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
     vector<string>result;
     solve(target,0,0,"",result,num,0);
     return result;
    }
};