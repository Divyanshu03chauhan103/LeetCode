class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int>result;

        for(int i:asteroids){
            if(i>0 || result.empty()) result.push_back(i);
            else if(i<0){
                
                while(!result.empty() && result.back()>0 && result.back()<abs(i)){
                    result.pop_back();
                }
                if(!result.empty() && result.back()==abs(i)) result.pop_back();
                else if(result.empty() || result.back()<0) result.push_back(i);
            }
        }
        return result;
    }
};