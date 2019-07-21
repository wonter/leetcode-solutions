/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.46%)
 * Likes:    265
 * Dislikes: 875
 * Total Accepted:    49.4K
 * Total Submissions: 161.9K
 * Testcase Example:  '3'
 *
 * Find the n^th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 2^31).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;
        long long counter = 9;
        long long start = 1;
        while (n > len * counter) {
            n -= len * counter;
            len++;
            counter *= 10;
            start *= 10;
        }

        return pos(start + (n - 1) / len, (n - 1 + len) % len + 1);
    }

private:
    int len(long long num) {
        num = abs(num);

        if (num == 0) {
            return 1;
        }

        int ret = 0;
        while (num) {
            num /= 10;
            ret++;
        }
        return ret;
    }

    int pos(long long num, int i) {
        if (i > len(num)) {
            abort();
        }

        if (num == 0) {
            return 0;
        }

        int counter = len(num) - i + 1;
        while (counter > 1) {
            num /= 10;
            counter--;
        }

        return num % 10;
    }
};

