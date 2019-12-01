class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        string str;
        if (n == 0) {
            str = "0";
        }
        while (n) {
            int x = n % 16;
            if (x >= 2 && x <= 9) {
                return "ERROR";
            }
            if (x < 10) {
                str.push_back(x + '0');
            } else {
                str.push_back('A' + x - 10);
            }
            n /= 16;
        }
        reverse(str.begin(), str.end());
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '0') {
                str[i] = 'O';
            } else if (str[i] == '1') {
                str[i] = 'I';
            }
        }
        return str;
    }
};