/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        if (A.empty()) {
            return "";
        }

        int n = A.size();
        int dp[1 << 12][12];
        int pre[1 << 12][12];
        int common[12][12];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                common[i][j] = str_common(A[i], A[j]);
            }
        }

        int min_len = INT_MAX;
        for (int i = 0; i < n; ++i) {
            min_len = min(min_len, dfs(0, i, A, common, dp, pre));
        }

        string ret;
        for (int head = 0; head < n; ++head) {
            if (dp[0][head] != min_len) {
                continue;
            }

            int status = 0;
            int pre_head = -1;
            while (status != (1 << n) - 1) {
                if (status == 0) {
                    ret += A[head];
                } else {
                    ret += A[head].substr(common[pre_head][head]);
                }

                int next_head = pre[status][head];
                int next_status = status | (1 << head);
                pre_head = head;
                head = next_head;
                status = next_status;
            }

            break;
        }
        return std::move(ret);
    }

private:
    int str_common(const string& a, const string& b) {
        int n = a.size();
        int m = b.size();
        for (int i = min(n, m); i >= 1; --i) {
            if (a.substr(n - i, i) == b.substr(0, i)) {
                return i;
            }
        }
        return 0;
    }

    int dfs(int status, int head, const vector<string>& A, int common[12][12], int dp[12][12], int pre[12][12]) {
        if (dp[status][head] != -1) {
            return dp[status][head];
        }

        int n = A.size();
        if (status == (1 << n) - 1) {
            return dp[status][head] = 0;
        }

        int counter = 0;    // 还有多少位是0
        for (int i = 0; i < n; ++i) {
            if ((status & (1 << i)) == 0) {
                ++counter;
            }
        }
        if (counter == 1) {
            return dp[status][head] = A[head].size();
        }

        dp[status][head] = INT_MAX;
        for (int next = 0; next < n; ++next) {
            if (status & (1 << next)) {
                continue;
            }
            if (next == head) {
                continue;
            }

            int temp = dfs(status | (1 << head), next, A, common, dp, pre) + A[head].size() - common[head][next];
            if (temp < dp[status][head]) {
                dp[status][head] = temp;
                pre[status][head] = next;
            }
        }
        return dp[status][head];
    }
};
// @lc code=end