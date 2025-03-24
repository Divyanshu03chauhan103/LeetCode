class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
            int result=0;

            sort(meetings.begin(),meetings.end());

            int end = meetings[0][1];

            int n=meetings.size();
            result+=meetings[0][0]-1;
            for(int i=1;i<n;i++){

                int start = meetings[i][0];

                if(start>end){
                    cout<<start<<" "<<end;
                    result+=start-end-1;
                }
                end=max(end,meetings[i][1]);
            }
            cout<<end;
            result+=days-end;
            return result;
    }
};