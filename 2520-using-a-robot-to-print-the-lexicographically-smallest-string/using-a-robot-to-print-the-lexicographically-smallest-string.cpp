class Solution {
public:
    string robotWithString(string s) {
        int n=s.length();
        vector<char>min_char(n);

        min_char[n-1]=s[n-1];

        for(int i=n-2;i>=0;i--){
            min_char[i]=min(min_char[i+1],s[i]);
        }

        int i=0;
        string t = "";
        string paper = "";
        while(i<n){

            char mini_char= i+1<n? min_char[i+1]:s[i];
            t.push_back(s[i]);

            while(!t.empty() && t.back()<=mini_char){
                paper.push_back(t.back());
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            paper.push_back(t.back());
            t.pop_back();
        }
        return paper;
    }
};