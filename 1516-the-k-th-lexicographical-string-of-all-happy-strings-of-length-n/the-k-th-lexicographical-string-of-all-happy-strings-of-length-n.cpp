class Solution {
public:
    bool isValid(string curr,char c){

        if(curr.empty()) return true;

        if(curr[curr.size()-1]==c) return false;

        return true;
    }
    void solve(string s,string curr,int n,vector<string>&result){

         if(curr.size() == n) {
            result.push_back(curr);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(isValid(curr,s[i])){
                curr.push_back(s[i]);
                solve(s,curr,n,result);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        
        string s ="abc";
        vector<string>result;

        solve(s,"",n,result);

        sort(result.begin(),result.end());
        return (k >  result.size())? "":result[k-1];
    }
};