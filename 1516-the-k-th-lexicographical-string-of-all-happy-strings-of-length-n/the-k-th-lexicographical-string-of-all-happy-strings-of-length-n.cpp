class Solution {
public:
    bool isValid(string curr,char c){

        if(curr.empty()) return true;

        if(curr[curr.size()-1]==c) return false;

        return true;
    }
    void solve(string s,string curr,int n,set<string>&result){

         if(curr.size() == n) {
            result.insert(curr);
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
        set<string>result;

        solve(s,"",n,result);

        int count = 1;
        
        for(auto i :result ){
            
            if(count==k){
                return i;
            }
            count++;
        }
        return "";
    }
};