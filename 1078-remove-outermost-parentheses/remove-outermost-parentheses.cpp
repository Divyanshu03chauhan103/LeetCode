class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int opened=0;

        string result ="";
        for(auto i:s){
            if(i=='('){
                if(opened>0)
                    result+=i;
                opened++;
            }
             else {
                if(opened>1)
                    result+=i;
                opened--;
            }
        }

        return result;
    }
};