class Solution {
public:
    int minOperations(string s) {
        int open = 1;     // pattern 1010
        int closed = 0;   // pattern 0101

        int result1 = 0;
        int result2 = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] != (open ? '1' : '0'))
                result1++;

            if(s[i] != (closed ? '1' : '0'))
                result2++;

            open = !open;
            closed = !closed;
        }

        return min(result1, result2);
    }
};