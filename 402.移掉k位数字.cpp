#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int need = n - k;

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() + n - i - 1 >= need && !st.empty() && st.top() > num[i]) {
                st.pop();
            }
            if (st.size() < need) {
                st.push(num[i]);
            }
        }

        string ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());

        int begin = 0;
        while (begin < ret.size() && ret[begin] == '0') {
            ++begin;
        }

        ret = ret.substr(begin);
        if (ret == "") {
            ret = "0";
        }
        return ret;
    }
};
// @lc code=end

