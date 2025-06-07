class Solution {
public:
    string clearStars(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        };

multiset<pair<char, int>, decltype(cmp)> chars(cmp);

        vector<bool> removed(s.size(), false);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                chars.insert({s[i], i});
            } else {
                if (!chars.empty()) {
                    auto it = chars.begin();
                    removed[it->second] = true;
                    chars.erase(it);
                }
            }
        }

        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*' && !removed[i]) {
                result += s[i];
            }
        }

        return result;
    }
};
