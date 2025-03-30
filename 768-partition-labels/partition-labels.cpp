class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>>max_index(26,{-1,-1});

        for(int i=0;i<s.length();i++){
            int index= s[i]-'a';
            if(max_index[index].first==-1){
                max_index[index].first=i;
            }
            max_index[index].second=i;
        }

         vector<pair<int, int>> intervals;
        for (auto &p : max_index) {
            if (p.first != -1) { 
                intervals.push_back(p);
            }
        }

        vector<int>result;
        sort(intervals.begin(),intervals.end());
        int first_val=intervals[0].first;
        int last_val=intervals[0].second;
        for(int i=1;i<intervals.size();i++){

            if(last_val>intervals[i].first){
                last_val=max(last_val,intervals[i].second);
            }
            else{
                result.push_back(last_val-first_val+1);
                first_val=intervals[i].first;
                last_val=intervals[i].second;
            }
        }
       
        result.push_back(last_val-first_val+1);
        return result;
    }
};