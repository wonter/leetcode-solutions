/*
 * @lc app=leetcode id=1591 lang=cpp
 *
 * [1591] Strange Printer II
 */

// @lc code=start
class Solution {
    const int ANY = 0;

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();

        unordered_set<int> removed;
        while (true) {
            int counter = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (targetGrid[i][j] == ANY) {
                        ++counter;
                    }
                }
            }
            if (counter == n * m) {
                return true;
            }

            int remove = ANY;
            for (int i = 1; i <= 60; ++i) {
                if (removed.find(i) == removed.end() && make_rectangle(targetGrid, i)) {
                    remove = i;
                    break;
                }
            }

            if (remove == ANY) {
                return false;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (targetGrid[i][j] == remove) {
                        targetGrid[i][j] = ANY;
                    }
                }
            }

            removed.insert(remove);
            
            // cout << "remove " << remove << endl;
            // print(targetGrid);
        }
    }

private:
    bool make_rectangle(vector<vector<int>>& targetGrid, int x) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();

        int top = INT_MAX;
        int bottom = INT_MIN;
        int leftest = INT_MAX;
        int rightest = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (targetGrid[i][j] != x) {
                    continue;
                }

                top = min(top, i);
                bottom = max(bottom, i);
                leftest = min(leftest, j);
                rightest = max(rightest, j);
            }
        }

        if (top == INT_MAX) {
            return false;
        }

        for (int i = top; i <= bottom; ++i) {
            for (int j = leftest; j <= rightest; ++j) {
                if (targetGrid[i][j] != x && targetGrid[i][j] != ANY) {
                    return false;
                }
            }
        }

        return true;
    }

    void print(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << targetGrid[i][j] << " ";
            }
            cout << endl;
        }
    }
};
// @lc code=end

