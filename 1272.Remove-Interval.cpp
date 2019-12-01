class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ret;
        for (size_t i = 0; i < intervals.size(); ++i) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (toBeRemoved[1] <= s) {
                ret.emplace_back(vector<int>{s, e});
            } else if (toBeRemoved[1] <= e) {
                if (toBeRemoved[0] > s) {
                    ret.emplace_back(vector<int>{s, toBeRemoved[0]});
                }
                if (toBeRemoved[1] < e) {
                    ret.emplace_back(vector<int>{toBeRemoved[1], e});
                }
            } else {
                if (toBeRemoved[0] > s && toBeRemoved[0] < e) {
                    ret.emplace_back(vector<int>{s, toBeRemoved[0]});
                } else if (toBeRemoved[0] >= e) {
                    ret.emplace_back(vector<int>{s, e});
                }
            }
        }
        return ret;
    }
};