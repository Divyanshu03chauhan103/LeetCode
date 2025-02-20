class Solution {
public:
    void solve(unordered_set<string>s,string &ans,int n,string curr){

        if(curr.size()==n){
            if(s.find(curr)==s.end())
                ans = curr;
            return;
        }
        if(ans != "") return ;
        solve(s,ans,n,curr+'0');
        solve(s,ans,n,curr+'1');
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string>s(nums.begin(),nums.end());
        string ans;
        int n= nums.size();
        solve(s,ans,n,"");

        return ans;
    }
};