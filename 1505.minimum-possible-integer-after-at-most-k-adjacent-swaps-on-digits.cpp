/*
 * @lc app=leetcode id=1505 lang=cpp
 *
 * [1505] Minimum Possible Integer After at Most K Adjacent Swaps On Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

int n;
int c[50005];
int lowbit(int x)
{
    return (-x)&x;
}
void add(int pos,int x)
{
    while(pos<=n)
    {
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
int query(int pos)
{
    int res=0;
    while(pos>0)
    {
        res+=c[pos];
        pos-=lowbit(pos);
    }
    return res;
}

class Solution {
public:
    string minInteger(string num, int k) {
        memset(c, 0, sizeof(c));

        n = num.size();

        priority_queue<int, vector<int>, greater<int>> digits[10];
        for (int i = 0; i < n; ++i) {
            digits[num[i] - '0'].push(i);
        }

        string ret;
        ret.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int digit = 0; digit < 10; ++digit) {
                if (digits[digit].empty()) {
                    continue;
                }

                int pos = digits[digit].top();
                int need_move = pos - query(pos + 1);
                // cout << i << " " << digit << " " << pos << " " << need_move << " " << k << endl;
                if (need_move <= k) {
                    digits[digit].pop();
                    ret[i] = num[pos];
                    k -= need_move;
                    add(pos + 1, 1);
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

