class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string>result;
        int n=s.size();
        for(int i=0;i<n;i+=k){
            string temp=s.substr(i,k);
            if(temp.size()!=k) temp+=string(k-temp.size(),fill);
            result.push_back(temp);
        }
        return result;
    }
};