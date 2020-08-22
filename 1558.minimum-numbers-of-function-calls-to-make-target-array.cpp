/*
 * @lc app=leetcode id=1558 lang=cpp
 *
 * [1558] Minimum Numbers of Function Calls to Make Target Array
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        while (sum != 0) {
            for (int& num : nums) {
                sum -= num;
                if (num & 1) {
                    num--;
                    ops++;
                }
                sum += num;
            }
            
            if (sum == 0) {
                break;
            }
            
            ops++;
            for (int& num : nums) {
                if (num == 0) {
                    continue;
                }
                
                sum -= num;
                num /= 2;
                sum += num;
            }
        }
        
        return ops;
    }
};
// @lc code=end

