/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0.0;
        int max_salary = INT_MIN;
        int min_salary = INT_MAX;
        for (int s : salary) {
            sum += s;
            max_salary = max(max_salary, s);
            min_salary = min(min_salary, s);
        }
        return 1.0 * (sum - max_salary - min_salary) / (salary.size() - 2);
    }
};
// @lc code=end

