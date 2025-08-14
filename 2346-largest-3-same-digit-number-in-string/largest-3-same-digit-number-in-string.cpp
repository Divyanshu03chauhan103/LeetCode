class Solution {
public:
    string largestGoodInteger(string num) {
        
        int max_num=INT_MIN;
        int n=num.size();
        for(int i=0;i<n-2;i++){
            string s=num.substr(i,3);
            bool check=true;
            for(int j=1;j<3;j++){
                if(s[j-1]!=s[j]){
                    check =false;
                    break;
                }
            }

            if(check){
                max_num=max(max_num,stoi(s));
            }
        }
        if(max_num==INT_MIN) return "";       
        return max_num==0?"000":to_string(max_num);
    }
};