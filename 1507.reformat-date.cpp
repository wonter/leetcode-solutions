/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */

// @lc code=start
class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        
        string d;
        string m;
        string y;
        ss >> d;
        ss >> m;
        ss >> y;
        
        int day = 0;
        for (int i = 0; i < d.size(); ++i) {
            if (isdigit(d[i])) {
                day = day * 10 + d[i] - '0';
            }
        }
        int month = get_month(m);
        int year = atoi(y.c_str());
        

        string ret = to_string(year);
        ret.push_back('-');
        if (month < 10) {
            ret.append("0" + to_string(month));
        } else {
            ret.append(to_string(month));
        }
        ret.push_back('-');
        if (day < 10) {
            ret.append("0" + to_string(day));
        } else {
            ret.append(to_string(day));
        }
        
        return ret;
    }

private:
    int get_month(const string& m) {
        if (m == "Jan") {
            return 1;
        }
        if (m == "Feb") {
            return 2;
        }
        if (m == "Mar") {
            return 3;
        }
        if (m == "Apr") {
            return 4;
        }
        if (m == "May") {
            return 5;
        }
        if (m == "Jun") {
            return 6;
        }
        if (m == "Jul") {
            return 7;
        }
        if (m == "Aug") {
            return 8;
        }
        if (m == "Sep") {
            return 9;
        }
        if (m == "Oct") {
            return 10;
        }
        if (m == "Nov") {
            return 11;
        }
        if (m == "Dec") {
            return 12;
        }
        return 111;
    }
};
// @lc code=end
