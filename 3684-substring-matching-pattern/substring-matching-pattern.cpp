class Solution {
public:
    bool hasMatch(string s, string p) {
        
        int index = -1;
        int n = s.length();
  
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*') {
                index = i;
                break;
            }
        }

        string s1 = p.substr(0, index);

        int i = 0;
        while (i < n) {
            if (s.substr(i, s1.length()) == s1) {
                break;
            }
            i++;
        }

        if (i == n) return false;

       
        s = s.substr(i + s1.length());

       
        return s.find(p.substr(index + 1)) != string::npos;
    }
};
