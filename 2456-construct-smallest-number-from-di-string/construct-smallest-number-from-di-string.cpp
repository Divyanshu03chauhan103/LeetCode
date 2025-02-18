class Solution {
public:
    bool isValid(string result, string pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if ((pattern[i] == 'I' && result[i] > result[i+1]) ||
                (pattern[i] == 'D' && result[i] < result[i+1])) {
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>&permutations,int n,vector<bool>&used,string curr){

        if(curr.size()==n){
            permutations.push_back(curr);
            return ;
        }

        for(int i=1;i<=n;i++){

            if(used[i]) continue;

            used[i] =true;
            curr.push_back(i+'0');
            solve(permutations,n,used,curr);
            used[i]=false;
            curr.pop_back();
        }

    }
    string smallestNumber(string pattern) {
        
        int n = pattern.size();

        vector<bool>used(n+2,false);

        vector<string>permutations;

        solve(permutations,n+1,used,"");
        
        for(auto i:permutations){

            if(isValid(i,pattern)) return i;
        }
        return "";
    }
};