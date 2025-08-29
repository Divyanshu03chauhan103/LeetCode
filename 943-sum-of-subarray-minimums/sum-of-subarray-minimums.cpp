class Solution {
public:
    vector<int>find_nse(vector<int>&arr){
        int n=arr.size();
        vector<int>result(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            result[i]= st.empty()==true?n:st.top();
            st.push(i);
        }
        return result;
    }
    vector<int>find_pse(vector<int>&arr){
        int n=arr.size();
        vector<int>result(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            result[i]= st.empty()==true?-1:st.top();
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int>nse = find_nse(arr);
        vector<int>pse = find_pse(arr);
        int mod=1e9+7;
        int n=arr.size();
        int result=0;
        for(int i=0;i<n;i++){

            int left = i-pse[i];
            int right=nse[i]-i;

            result=(result+(left*right*1LL*arr[i])%mod)%mod;
        }
        return result;
    }
};