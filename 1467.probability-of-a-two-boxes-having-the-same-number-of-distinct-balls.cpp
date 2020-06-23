/*
 * @lc app=leetcode id=1467 lang=cpp
 *
 * [1467] Probability of a Two Boxes Having The Same Number of Distinct Balls
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        _a[0] = 1;
        for (int i = 1; i < 49; ++i) {
            _a[i] = _a[i - 1] * i;
        }
    }

    double getProbability(vector<int>& balls) {
        if (balls.empty()) {
            return 0.0;
        }

        double counter = 0;
        vector<int> box2(balls.size(), 0);
        dfs(balls, box2, 0, counter);

        return counter / permutations(balls);
    }

    void dfs(vector<int>& box1, vector<int>& box2, int ball_idx, double& counter) {
        int n = box1.size();

        if (ball_idx >= n) {
            int box1_distinct = 0;
            int box1_count = 0;
            int box2_distinct = 0;
            int box2_count = 0;

            for (int i = 0; i < n; ++i) {
                if (box1[i] > 0) {
                    box1_count += box1[i];
                    box1_distinct += 1;
                }
                if (box2[i] > 0) {
                    box2_count += box2[i];
                    box2_distinct += 1;
                }
            }

            if (box1_count == box2_count && box1_distinct == box2_distinct) {
                counter += permutations(box1) * permutations(box2);
            }

            return;
        }

        for (int choose = 0; choose <= box1[ball_idx]; ++choose) {
            box1[ball_idx] -= choose;
            box2[ball_idx] += choose;
            dfs(box1, box2, ball_idx + 1, counter);
            box1[ball_idx] += choose;
            box2[ball_idx] -= choose;
        }
    }

private:
    double permutations(const vector<int>& balls) {
        double b = 1.0;
        int total = 0;
        for (int ball : balls) {
            total += ball;
            b = b * _a[ball];
        }
        return _a[total] / b;
    }

    double _a[100];
};
// @lc code=end

