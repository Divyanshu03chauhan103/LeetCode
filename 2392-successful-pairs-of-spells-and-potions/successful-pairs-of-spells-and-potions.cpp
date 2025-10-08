class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int>result;
        sort(potions.begin(),potions.end());
        for(int i : spells){

            int first_ind = binary_search(i,potions,success);
            
            
            int nOfS = potions.size()-first_ind;
            if(first_ind ==-1) nOfS=0;
            result.push_back(nOfS);
        }
        return result;
    }

    int binary_search(int ele,vector<int>&potions, long long success){

        int low=0;
        int high=potions.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(1LL*ele*potions[mid]>=success){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};