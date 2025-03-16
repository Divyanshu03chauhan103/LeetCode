class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result = strs[0];

        for(int i=1;i<strs.size();i++){

            int j=0;
            while(strs[i][j] == result[j] && j<strs[i].length() && j<result.length()){
                j++;
            }
            if(j==0) return "";
            result=result.substr(0,j);
        }

        return result;
    }
};