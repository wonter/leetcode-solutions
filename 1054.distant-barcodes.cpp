/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> counter;
        for (int barcode : barcodes) {
            counter[barcode]++;
        }

        priority_queue<pair<int, int>> counter_que;
        for (auto p : counter) {
            counter_que.emplace(p.second, p.first);
        }

        vector<int> ret;
        while (!counter_que.empty()) {
            pair<int, int>  top1 = counter_que.top();
            counter_que.pop();
            ret.emplace_back(top1.second);
            if (!counter_que.empty()) {
                pair<int, int> top2 = counter_que.top();
                counter_que.pop();
                ret.emplace_back(top2.second);
                --top2.first;
                if (top2.first != 0) {
                    counter_que.emplace(top2);
                }
            }
            --top1.first;
            if (top1.first != 0) {
                counter_que.emplace(top1);
            }
        }
        return ret;
    }
};

