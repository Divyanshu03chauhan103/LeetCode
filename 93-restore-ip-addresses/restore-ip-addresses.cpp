class Solution {
public:
    bool check(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void solve(string s, int i, vector<string>& result, string final, int dot) {
        if (dot > 4) return; 

        if (i == s.size() && dot == 4) {
            result.push_back(final);
            return;
        }

        for (int j = 1; j <= 3 && i + j <= s.size(); j++) {
            string curr_str = s.substr(i, j);
            if (check(curr_str)) {
                solve(s, i + j, result, final + (final.empty() ? "" : ".") + curr_str, dot + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if (n < 4 || n > 12) return {};

        vector<string> result;
        solve(s, 0, result, "", 0);
        return result;
    }
};
