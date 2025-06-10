class Solution {
public:
    int maxDifference(string s) {
        
        int n=s.length();

        vector<int>freq(26,0);
        
        for(char i:s){

            int ind=i-'a';
            freq[ind]++;    
        }
        int odd = INT_MIN;
        int even=INT_MAX;
        for(int i:freq){

            if(i%2==1){
                
                odd=max(odd,i);
                
            }else{
                if(i!=0)
                    even=min(even,i);
              
            }
        }
        
        return odd-even;
    }
};