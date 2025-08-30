class Solution {
public:
    vector<int>find_nse(vector<int>&arr){

        int n=arr.size();

        stack<int>st;

        vector<int>result(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            result[i]=st.empty()?n:st.top();

            st.push(i);
        }
        return result;
    }

    vector<int>find_pse(vector<int>&arr){

        int n=arr.size();

        stack<int>st;

        vector<int>result(n,-1);

        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            result[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse = find_nse(heights);
        vector<int>pse = find_pse(heights);
        int result=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int h=heights[i];
            
            int w = nse[i]  -pse[i]-1;
            result=max(result,h*w);
        }
        return result;
    }
};