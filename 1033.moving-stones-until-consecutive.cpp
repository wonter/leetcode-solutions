/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr{a, b, c};
        sort(arr.begin(), arr.end());
        
        int min_step = 0;
        if (arr[1] == arr[0] + 1 && arr[2] == arr[1] + 1) {
            min_step = 0;
        } else if (arr[1] == arr[0] + 1 || arr[2] == arr[1] + 1 || arr[1] == arr[0] + 2 || arr[2] == arr[1] + 2) {
            min_step = 1;
        } else {
            min_step = 2;
        }

        int max_step = (arr[1] - arr[0] - 1) + (arr[2] - arr[1] - 1);
        return vector<int>{min_step, max_step};
    }
};

