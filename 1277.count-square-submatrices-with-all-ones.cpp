class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> rowsum(n, vector<int>(m, 0));
        vector<vector<int>> colsum(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    rowsum[i][j] = matrix[i][j];
                } else {
                    rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j];
                }

                if (i == 0) {
                    colsum[j][i] = matrix[i][j];
                } else {
                    colsum[j][i] = colsum[j][i - 1] + matrix[i][j];
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; i + k < n && j + k < m; ++k) {
                    if (prefixsum(rowsum, i + k, j, j + k) == k + 1 && prefixsum(colsum, j + k, i, i + k) == k + 1) {
                        ++counter;
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
        return counter;
    }

    int prefixsum(const vector<vector<int>>& sumarr, int i, int s, int e) {
        if (s == 0) {
            return sumarr[i][e];
        }

        return sumarr[i][e] - sumarr[i][s - 1];
    }
};