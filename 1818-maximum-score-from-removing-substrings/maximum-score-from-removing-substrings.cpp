class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first=(x>y)? 'a':'b';
        char second=(x>y)? 'b':'a';
         if(x < y)swap(x, y);
        
        int cf=0;
        int cs=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==first) cf++;
            else if(s[i]==second){
              cs++;
              if(cf>0)  {
                
                ans+=x;
                cf--;
                cs--;
              }

            }
            else{
               ans+=min(cf,cs)*y;
               cf=0;
               cs=0;
            }
        }
        ans+=min(cf,cs)*y;
        return ans;

        
    }
};