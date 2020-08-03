/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> que;
        unordered_map<int, int> win_count;

        for (int num : arr) {
            que.push_back(num);
        }
        
        while (true) {
            int first = que.front(); que.pop_front();
            int second = que.front(); que.pop_front();
            int winner = max(first, second);
            int loser = min(first, second);
 
            win_count[winner] += 1;
            if (win_count[winner] == min((int)arr.size(), k)) {
                return winner;
            }

            que.push_front(winner);
            que.push_back(loser);
        }

        return -1;
    }
};
// @lc code=end

