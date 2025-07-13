class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        int result=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0;
        int j=0;
        int n1=players.size();
        int n2=trainers.size();   

        while(i<n1 && j<n2){
            if(players[i]<=trainers[j]){
                i++;
                result++;
                
            }
            j++;
        }
        return result;
    }
};