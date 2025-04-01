class Solution {
public:
    string makeGood(string s) {
       string result="";

       for(auto i:s){
        
        if(!result.empty() && abs(result.back()-i)==32)
            result.pop_back();
        else result.push_back(i);
       }
       return result;
    }
};
