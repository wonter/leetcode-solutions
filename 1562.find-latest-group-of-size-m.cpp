/*
 * @lc app=leetcode id=1562 lang=cpp
 *
 * [1562] Find Latest Group of Size M
 */

// @lc code=start
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        set<pair<int, int>> st;
        st.insert({1, arr.size()});

        if (arr.size() == m) {
            return arr.size();
        }

        for (int i = arr.size() - 1; i >= 0; --i) {
            pair<int, int> p = {arr[i], arr[i]};
            auto it = st.upper_bound(p);
            if (it == st.end() || it->first != arr[i]) {
                --it;
            }

            if (it->second - arr[i] == m) {
                return i;
            }
            if (arr[i] - it->first == m) {
                return i;
            }

            if (arr[i] != it->first) {
                st.insert({it->first, arr[i] - 1});
            }
            if (arr[i] != it->second) {
                st.insert({arr[i] + 1, it->second});
            }

            st.erase(it);
        }

        return -1;
    }
};
// @lc code=end
