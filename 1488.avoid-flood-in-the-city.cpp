/*
 * @lc app=leetcode id=1488 lang=cpp
 *
 * [1488] Avoid Flood in The City
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        if (rains.empty()) {
            return {};
        }

        int n = rains.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> lake;
        set<int> dry_idx;
        unordered_map<int, int> rain_idx;

        for (int day = 0; day < n; ++day) {
            if (rains[day] == 0) {
                dry_idx.insert(day);
                continue;
            }

            ans[day] = -1;

            if (lake[rains[day]] == 0) {
                lake[rains[day]] = 1;
                rain_idx[rains[day]] = day;
                continue;
            }

            auto it = dry_idx.upper_bound(rain_idx[rains[day]]);
            if (it == dry_idx.end()) {
                return {};
            }

            ans[*it] = rains[day];
            rain_idx[rains[day]] = day;
            dry_idx.erase(it);
        }

        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                ans[i] = 1;
            }
        }

        return ans;
    }
};
// @lc code=end

