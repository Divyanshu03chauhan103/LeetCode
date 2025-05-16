class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int i=0;
        int j=0;
        int n=g.size();
        int N=s.size();
        int result=0;
        while(i<n && j<N){
            if(g[i]<=s[j]){
                result++;  
                i++;
            }
            j++;
        }
        return result;
    }
};