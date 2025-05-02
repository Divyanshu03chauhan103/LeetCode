class Solution {
public:
    string pushDominoes(string dominoes) {
        
        queue<pair<char,int>>states;
        int n=dominoes.size();
        for(int i=0;i<dominoes.length();i++){
            if(dominoes[i]!='.') states.push({dominoes[i],i});
        }

        while(!states.empty()){

            auto curr_state = states.front();
            int index=curr_state.second;
            char state=curr_state.first;
            states.pop();
            if(state=='L'){
                
                if(index>0 && dominoes[index-1]=='.'){
                    dominoes[index-1]='L';
                    states.push({'L',index-1});
                }
            }
            else{
                if(index<n-1 && dominoes[index+1]=='.'){
                    if(index<n-2 && dominoes[index+2]=='L')
                        states.pop();
                    else{
                        dominoes[index+1]='R';
                        states.push({'R',index+1});
                    }
                }
            }
        }

        return dominoes;
    }
};