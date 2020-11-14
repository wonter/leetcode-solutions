/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<pair<int, int>> intervals;
        for (vector<int>& piece : pieces) {
            int first = -1;
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] == piece[0]) {
                    first = i;
                    break;
                }
            }

            if (first == -1) {
                return false;
            }

            int last = first;
            for (int num : piece) {
                if (num == arr[last]) {
                    ++last;
                } else {
                    return false;
                }
            }

            intervals.emplace_back(pair<int, int>{first, last});
        }

        // for (int i = 1; i < intervals.size(); ++i) {
        //     cout << intervals[i].first << " " << intervals[i].second << endl;
        // }

        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first < rhs.first;
        });

        if (intervals.front().first != 0) {
            return false;
        }
        if (intervals.back().second != arr.size()) {
            return false;
        }

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first != intervals[i - 1].second) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

