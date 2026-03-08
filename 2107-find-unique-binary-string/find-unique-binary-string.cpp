class Solution {
public:
    void solve(unordered_set<string>s,string &ans,int n,string &curr){

        if(curr.size()==n){
            //checks whether the string is present in the ans or not 
            if(s.find(curr)==s.end())
                ans = curr;
            return;
        }
        // if ans is found then no need to check further
        if(ans != "") return ;
        
        curr.push_back('0');
        solve(s,ans,n,curr);
        //backtrack
        curr.pop_back();
        curr.push_back('1');
        solve(s,ans,n,curr);
        //backtrack
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string>s(nums.begin(),nums.end());
        string ans;
        int n= nums.size();
        string curr;
        solve(s,ans,n,curr);

        return ans;
    }
};