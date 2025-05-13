class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        vector<int>freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }
        int mod = 1e9+7;
        while(t--){
            
           vector<int>temp(26,0);
            for(int i=0;i<26;i++){

                char ch= i+'a';
                int count = freq[i];

                if(ch == 'z'){
                    temp[0]= (temp[0]+count)%mod;
                    temp[1]=(temp[1]+count)%mod;
                }else{
                    temp[ch - 'a'+1]= (temp[ch-'a'+1]+count)%mod;
                }
            }
            freq=temp;
        }

        int result =0;
        for(int i:freq){
            result=(result+i)%mod;
        }
        return result;
    }
};