class Solution {
private:
    int is_digit(char c) {
        int k = c - '0';
        return k >= 0 && k <= 9;
    }
    bool is_operator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
public:
    int calculate(string s) {
        vector<int> previous_nums;
        int n = s.length();
        int num_cur = 0;
        char _operator = '+';
        for (int i = 0; i < n; ++i) {
            if (is_digit(s[i])) {
                int digit = s[i] - '0';
                num_cur *= 10;
                num_cur += digit;
            }
            if (i == n - 1 || is_operator(s[i])) {
                if (_operator == '+') {
                    previous_nums.push_back(num_cur);
                }
                else if (_operator == '-') {
                    previous_nums.push_back(-num_cur);
                }
                else if (_operator == '*') {
                    int _result = previous_nums.back() * num_cur;
                    previous_nums.pop_back();
                    previous_nums.push_back(_result);

                }
                else {
                    int _result = previous_nums.back() / num_cur;
                    previous_nums.pop_back();
                    previous_nums.push_back(_result);
                }
                _operator = s[i];
                num_cur = 0;
            }
        }
        int ans = 0;
        int it = (int)(previous_nums.size());
        for (int i = 0; i < it; ++i) {
            int cur = previous_nums.back();
            previous_nums.pop_back();
            ans += cur;
        }
        return ans;
    }
};