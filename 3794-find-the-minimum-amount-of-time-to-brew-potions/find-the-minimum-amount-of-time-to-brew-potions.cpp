class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size() , m = mana.size();

        vector<long long>done(n,0);

        for(int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(j==0){
                    done[j] = done[j] + mana[i] * skill[j] * 1LL;
                }else{
                    done[j] = max(done[j],done[j-1]) + mana[i] * skill[j] * 1LL;
                }
            }

            for(int k = n-2 ; k >= 0 ; k--){

                done[k] = done[k+1] -1LL*mana[i]*skill[k+1];
            }
        }
        return done[n-1];
    }
};