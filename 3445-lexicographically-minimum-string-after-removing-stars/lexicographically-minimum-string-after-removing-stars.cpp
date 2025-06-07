class Solution {
public:
    string clearStars(string s) {
        
        auto cmp = [](const pair<char,int>a,const pair<char,int>b){
            if(a.first == b.first) return a.second<b.second;
            return a.first>b.first;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)>pq;

        int n=s.length();
        vector<int>removed(n,0);

        for(int i=0;i<n;i++){

            if(s[i]!='*'){
                pq.push({s[i],i});
            }else{
                int ind=pq.top().second;
                removed[ind]=1;
                pq.pop();
            }
        }

        string res="";

        for(int i=0;i<n;i++){
            if(!removed[i] && s[i]!='*')
                res+=s[i];
        }

        return res;
    }
};