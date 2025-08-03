class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;

        unordered_set<string>st(wordList.begin(),wordList.end());

        st.erase(beginWord);

        q.push({beginWord,1});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string word = curr.first;
            int steps=curr.second;
            if(word==endWord) return steps;
            for(int i=0;i<word.length();i++){

                char original = word[i];

                for(int j='a' ; j<='z' ;j++){
                    word[i]=j;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,steps+1});
                    }

                }
                word[i]=original;
            }
        }
        return 0;
    }
};