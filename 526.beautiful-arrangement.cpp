/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
public:
    int countArrangement(int N) {
        vector<int> vec;
        for (int i = 1; i <= N; ++i) {
            vec.emplace_back(i);
        }

        return dfs(vec, 0);
    }

private:
    int dfs(vector<int>& vec, int pos) {
        if (pos >= vec.size()) {
            return 1;
        }

        int counter = 0;
        for (int i = pos; i < vec.size(); ++i) {
            if (vec[i] % (pos + 1) != 0 && (pos + 1) % vec[i] != 0) {
                continue;
            }

            swap(vec[i], vec[pos]);
            counter += dfs(vec, pos + 1);
            swap(vec[i], vec[pos]);
        }
        return counter;
    }
};
// @lc code=end

