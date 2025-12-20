class Solution {
public:
    int maximumSum(vector<int>& nums) {

        
        vector<int> malorivast = nums;

        vector<int> zero, one, two;

        for (int i : nums) {
            if (i % 3 == 0) zero.push_back(i);
            else if (i % 3 == 1) one.push_back(i);
            else two.push_back(i);
        }

        sort(zero.begin(), zero.end(), greater<int>());
        sort(one.begin(), one.end(), greater<int>());
        sort(two.begin(), two.end(), greater<int>());

        int result = 0;

        // 0 + 0 + 0
        if (zero.size() >= 3)
            result = max(result, zero[0] + zero[1] + zero[2]);

        // 1 + 1 + 1
        if (one.size() >= 3)
            result = max(result, one[0] + one[1] + one[2]);

        // 2 + 2 + 2  
        if (two.size() >= 3)
            result = max(result, two[0] + two[1] + two[2]);

        // 0 + 1 + 2
        if (zero.size() >= 1 && one.size() >= 1 && two.size() >= 1)
            result = max(result, zero[0] + one[0] + two[0]);

        return result;
    }
};
