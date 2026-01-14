class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;

        st.erase(beginWord);

        q.push({beginWord,1});

        while(!q.empty()){

            pair<string,int>p = q.front();
            q.pop();
            string curr = p.first;
            int len=p.second;
            if(curr==endWord) return len;
            for(int i=0;i<curr.length();i++){

                char originalChar = curr[i];

                for(int c='a';c<='z';c++){
                    curr[i]=c;
                    if(st.count(curr)){
                        q.push({curr,len+1});
                        st.erase(curr);
                    }

                }
                curr[i]=originalChar;
            }
        }
        return 0;
    }
};