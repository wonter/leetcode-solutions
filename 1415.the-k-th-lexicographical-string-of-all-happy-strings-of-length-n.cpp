/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
class Solution {
public:
    string getHappyString(int n, int k) {
        memset(str, 0, sizeof(str));

        int counter = 0;
        dfs(0, n, k, counter);

        if (counter != k) {
            return "";
        }

        return string(str);
    }

private:
    void dfs(int i, int n, int k, int& counter) {
        if (i == n) {
            ++counter;
            return;
        }

        if (counter == k) {
            return;
        }

        for (char letter = 'a'; letter <= 'c' && counter < k; ++letter) {
            if ((i == 0) || (letter != str[i - 1])) {
                str[i] = letter;
                dfs(i + 1, n, k, counter);
            }
        }
    }

    char str[22];
};
// @lc code=end

