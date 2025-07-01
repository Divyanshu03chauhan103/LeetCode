class Solution {
public:
    int possibleStringCount(string word) {
        
        int result=0;
        int n=word.size();
        char prev=word[0];
        for(int i=1;i<n;i++){
            int count=0;
            while(i<n && prev == word[i])
            {
                i++;
                count++;
            }            
            result+=count;
            prev=word[i];
        }
        return result+1;
    }
};