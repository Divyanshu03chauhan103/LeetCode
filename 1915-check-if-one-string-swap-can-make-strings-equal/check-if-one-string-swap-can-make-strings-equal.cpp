class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n_s1 = s1.length();
        int n_s2 = s2.length();

        if (n_s1 != n_s2) return false; // Length mismatch

        int first_index = -1, second_index = -1;
        int mismatch_count = 0;

        for (int i = 0; i < n_s1; i++) {
            if (s1[i] != s2[i]) {
                mismatch_count++;

                if (first_index == -1) 
                    first_index = i;
                else if (second_index == -1) 
                    second_index = i;
                else 
                    return false; // More than two mismatches
            }
        }

        // If no mismatch, strings are already equal
        if (mismatch_count == 0) return true;

        // If only one mismatch, it's impossible to swap -> return false
        if (mismatch_count != 2) return false;

        // Swap and check if they become equal
        swap(s1[first_index], s1[second_index]);

        return s1 == s2;
    }
};
