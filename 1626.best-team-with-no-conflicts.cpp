/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
struct Player {
    int age;
    int score;
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<Player> players;
        int n = scores.size();
        for (int i = 0; i < n; ++i) {
            players.emplace_back(Player{ages[i], scores[i]});
        }
        sort(players.begin(), players.end(), [](const Player& lhs, const Player& rhs) {
            if (lhs.age == rhs.age) {
                return lhs.score < rhs.score;
            }
            return lhs.age < rhs.age;
        });

        int ret = 0;
        int dp[1010] = {0};
        for (int i = 0; i < n; ++i) {
            dp[i] = players[i].score;
            for (int j = 0; j < i; ++j) {
                if (players[j].age == players[i].age || players[j].score <= players[i].score) {
                    dp[i] = max(dp[i], players[i].score + dp[j]);
                }
            }
            cout << i << " " << dp[i] << endl;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

