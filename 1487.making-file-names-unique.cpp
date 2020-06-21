/*
 * @lc app=leetcode id=1487 lang=cpp
 *
 * [1487] Making File Names Unique
 */

// @lc code=start
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> counter;
        for (string& name : names) {
            auto it = counter.find(name);

            if (it == counter.end()) {
                counter[name] = 1;
                continue;
            }

            int suffix = it->second;
            string new_name = name + "(" + to_string(suffix) + ")";
            while (counter.find(new_name) != counter.end()) {
                ++suffix;
                new_name = name + "(" + to_string(suffix) + ")";
            }
            counter[name] = suffix;
            counter[new_name] = 1;

            name = new_name;
        }
        return names;
    }
};
// @lc code=end

