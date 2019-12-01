/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int counter = 0;
        solve(sea, topRight, bottomLeft, counter);
        return counter;
    }

private:
    void solve(Sea& sea, const vector<int>& topRight, const vector<int>& bottomLeft, int& counter) {
        if (!sea.hasShips(topRight, bottomLeft)) {
            return;
        }

        if (topRight[0] > bottomLeft[0]) {
            // 二分X
            int new_x = (topRight[0] + bottomLeft[0]) / 2;
            solve(sea, vector<int>{new_x, topRight[1]}, bottomLeft, counter);
            solve(sea, topRight, vector<int>{new_x, bottomLeft[1]}, counter);
            return;
        }

        if (topRight[1] > bottomLeft[1]) {
            // 二分Y
            int new_y = (topRight[1] + bottomLeft[1]) / 2;
            solve(sea, topRight, vector<int>{bottomLeft[0], new_y}, counter);
            solve(sea, vector<int>{topRight[0], new_y}, bottomLeft, counter);
            return;
        }

        ++counter;
    }
};