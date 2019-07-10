/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.95%)
 * Likes:    1118
 * Dislikes: 422
 * Total Accepted:    247.9K
 * Total Submissions: 845.5K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(max(10, n), true);
        is_prime[1] = false;

        for (int i = 2; i * i < n; i++) {
           if (!is_prime[i]) {
               continue;
           }

           for (int j = i * i; j < n; j += i) {
              is_prime[j] = false;
           }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
           if (is_prime[i]) {
                count++;
           }
        }

        return count;
    }
};

