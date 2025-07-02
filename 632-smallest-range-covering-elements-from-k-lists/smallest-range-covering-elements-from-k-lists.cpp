class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {  
        int k=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; 
        vector<int>range = {-1000000,1000000};
        int max_ele=INT_MIN;
        for(int i=0;i<k;i++){
            int ele = nums[i][0];
            pq.push({ele,i,0});
            max_ele=max(max_ele,ele);
        }

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int ele=curr[0];
            int list = curr[1];
            int list_ind = curr[2];

            if(range[1]-range[0]>max_ele-ele){
                range[1]=max_ele;
                range[0]=ele;
            }
            
            int next_ele_ind=list_ind+1;
            if(next_ele_ind>=nums[list].size()) break;
            max_ele=max(max_ele,nums[list][next_ele_ind]);
            pq.push({nums[list][next_ele_ind],list,next_ele_ind});
        }
        return range;
    }
};