class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string first = num.substr(0, i);
                string second = num.substr(i, j - i);

                // Skip if either has leading zeros
                if ((first.size() > 1 && first[0] == '0') ||
                    (second.size() > 1 && second[0] == '0'))
                    continue;

                if (isValid(first, second, num.substr(j)))
                    return true;
            }
        }
        return false;
    }

    bool isValid(string first, string second, string remaining) {
        while (!remaining.empty()) {
            string sum = addStrings(first, second);

            if (remaining.substr(0, sum.size()) != sum)
                return false;

            remaining = remaining.substr(sum.size());
            first = second;
            second = sum;
        }
        return true;
    }

    string addStrings(const string& num1, const string& num2) {
        string result;
        int carry = 0, i = num1.size()-1, j = num2.size()-1;

        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? (num1[i--] - '0') : 0;
            int y = j >= 0 ? (num2[j--] - '0') : 0;
            int sum = x + y + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
