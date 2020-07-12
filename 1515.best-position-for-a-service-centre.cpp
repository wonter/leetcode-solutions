/*
 * @lc app=leetcode id=1515 lang=cpp
 *
 * [1515] Best Position for a Service Centre
 */

// @lc code=start
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double xleft = 0;
        double xright = 1000.0;
        double y = 0.0;

        while (fabs(xleft - xright) > 1e-7) {
            double midxl = (xleft + xright) / 2;
            double midxr = (midxl + xright) / 2;

            double midyl = 0.0;
            double midyr = 0.0;

            double distance_midxl = euclidean_distance(positions, midxl, &midyl);
            double distance_midxr = euclidean_distance(positions, midxr, &midyr);
            if (distance_midxl < distance_midxr) {
                y = midyl;
                xright = midxr;
            } else {
                y = midyr;
                xleft = midxl;
            }
        }

        return euclidean_distance(positions, xleft, y);
    }

private:
    double euclidean_distance(const vector<vector<int>>& positions, double x, double* y) {
        double yleft = 0;
        double yright = 1000.0;
        while (fabs(yleft - yright) > 1e-7) {
            double midyl = (yleft + yright) / 2;
            double midyr = (midyl + yright) / 2;

            if (euclidean_distance(positions, x, midyl) < euclidean_distance(positions, x, midyr)) {
                yright = midyr;
            } else {
                yleft = midyl;
            }
        }

        *y = yleft;

        return euclidean_distance(positions, x, *y);
    }

    double euclidean_distance(const vector<vector<int>>& positions, double x, double y) {
        double ret = 0;
        for (const vector<int>& position : positions) {
            ret += sqrt((position[0] - x) * (position[0] - x) + (position[1] - y) * (position[1] - y));
        }
        return ret;
    }
};
// @lc code=end

