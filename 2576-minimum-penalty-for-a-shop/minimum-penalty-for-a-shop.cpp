class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix_n(n+1, 0);   
        vector<int> suffix_y(n+1, 0);   

        
        for (int i = 0; i < n; i++) {
            prefix_n[i+1] = prefix_n[i] + (customers[i] == 'N');
        }

        
        for (int i = n-1; i >= 0; i--) {
            suffix_y[i] = suffix_y[i+1] + (customers[i] == 'Y');
        }

        
        int best = 0;
        int min_penalty = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int penalty = prefix_n[i] + suffix_y[i];
            if (penalty < min_penalty) {
                min_penalty = penalty;
                best = i;
            }
        }
        return best;
    }
};
