class Solution {
public:
    bool solve(int i,int n, vector<int>&result,vector<bool>&used){

        if(i>=2*n-1) return true;

        if(result[i]!=-1){
            if(solve(i+1,n,result,used))
                return true;
            return false;
            // return solve(i+1,n,result,used);
        }

        for(int num=n;num>=1;num--){

            if(used[num]) continue;

            result[i] =num ;
            used[num]=true;

            if(num==1){
                if(solve(i+1,n,result,used) )//
                    return true;
            }
            else{

                int j=i+result[i];

                if(j<result.size() && result[j]==-1){
                    result[j]=num;
                    if(solve(i+1,n,result,used))
                        return true;
                    result[j] =-1;
                }

            }
            result[i]=-1;
            used[num]=false;
        }

        return false;

    }
    vector<int> constructDistancedSequence(int n) {
        
        vector<int>result(2*n-1,-1);
        vector<bool>used(n+1,false);

        solve(0,n,result,used);

        return result;
    }
};