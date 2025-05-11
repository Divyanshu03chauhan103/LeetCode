class Solution {
public:
    int minDeletion(string s, int k) {
        
       vector<int>st(26,0);
        int count=0;
        for(auto i:s){
           
            char index = i-'a';
            if(st[index]==0) count++;
             st[i-'a']++;
        }

        int extra = count-k;
        
        if(extra<=0) return 0;
        sort(st.begin(),st.end());
        int j=0;
        while(st[j]==0) j++;
        int result=0;
        while(extra && j<26){
            result+=st[j];
            j++;
            extra--;
        }
        return result;
    }
};