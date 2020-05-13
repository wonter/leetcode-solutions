/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> vec = { 0 };
        int minimum = -1;
        int maximum = 1;
        for (char ch : S) {
            if (ch == 'I') {
                vec.emplace_back(maximum);
                ++maximum;
            } else {
                vec.emplace_back(minimum);
                --minimum;
            }
        }

        int min_num = *min_element(vec.begin(), vec.end()); // 0 or negative
        for (int& num : vec) {
            num += abs(min_num);
        }

        return std::move(vec);
    }
};
// @lc code=end

