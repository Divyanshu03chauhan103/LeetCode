
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
       
        vector<int>required;
        int mod=1e9+7;
        int N=n;
        
         while (N) {
            int exp = floor(log2(N));  //gives me highest power less then N
            int num = 1 << exp;        //calculate the power using left shift
            N = N - num;               
            required.push_back(num);   
        }

        reverse(required.begin(), required.end());
        
        vector<int> result;
        for (auto &nums : queries) {
            int left = nums[0];
            int right = nums[1];
            long long product = required[left];
            for (int i = left+1; i <= right; i++) {
                product = (product * required[i]) % mod;
            }
            result.push_back((int)product);
        }
        return result;
    }
};

