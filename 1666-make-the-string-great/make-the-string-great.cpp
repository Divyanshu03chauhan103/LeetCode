class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while (i < (int)s.size() - 1) {  // Ensure we don’t go out of bounds
            if (abs(s[i] - s[i + 1]) == 32) {  // Check if they are the same letter in different cases
                s.erase(i, 2);  // Remove both characters
                i = max(0, i - 1);  // Move back one step to check new adjacent characters
            } else {
                i++;  // Move forward only if no removal occurs
            }
        }
        return s;
    }
};
