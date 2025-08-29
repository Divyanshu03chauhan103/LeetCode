class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n=nums.size();
        vector<int>nge = find_nge(nums);
        vector<int>nse=find_nse(nums);
        vector<int>pse=find_pse(nums);
        vector<int>pge=find_pge(nums);
        long long large=0;
      
        long long small=0;
        for(int i=0;i<n;i++){
            
            int right_s=nse[i]-i;
            int left_s=i-pse[i];

            int right_g=nge[i]-i;
            int left_g=i-pge[i];

            large += (left_g * right_g * 1LL * nums[i]);
            small += (left_s * right_s * 1LL * nums[i]);
        }

        return large-small;
    }

    vector<int>find_nse(vector<int>&arr){

        int n=arr.size();
        stack<int>st;
        vector<int>result(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            result[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return result;
        
    }

    vector<int>find_pse(vector<int>&arr){

        int n=arr.size();
        stack<int>st;
        vector<int>result(n,n);

        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            result[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return result;
        
    }

    vector<int>find_nge(vector<int>&arr){

        int n=arr.size();
        stack<int>st;
        vector<int>result(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }

            result[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return result;
        
    }
    vector<int>find_pge(vector<int>&arr){

        int n=arr.size();
        stack<int>st;
        vector<int>result(n,n);

        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }

            result[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return result;
        
    }
};