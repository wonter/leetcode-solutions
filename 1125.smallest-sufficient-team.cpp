/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 *
 * https://leetcode.com/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (31.56%)
 * Likes:    25
 * Dislikes: 3
 * Total Accepted:    525
 * Total Submissions: 1.7K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * In a project, you have a list of required skills req_skills, and a list of
 * people.  The i-th person people[i] contains a list of skills that person
 * has.
 * 
 * Consider a sufficient team: a set of people such that for every required
 * skill in req_skills, there is at least one person in the team who has that
 * skill.  We can represent these teams by the index of each person: for
 * example, team = [0, 1, 3] represents the people with skills people[0],
 * people[1], and people[3].
 * 
 * Return any sufficient team of the smallest possible size, represented by the
 * index of each person.
 * 
 * You may return the answer in any order.  It is guaranteed an answer
 * exists.
 * 
 * 
 * Example 1:
 * Input: req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * Output: [0,2]
 * Example 2:
 * Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= req_skills.length <= 16
 * 1 <= people.length <= 60
 * 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
 * Elements of req_skills and people[i] are (respectively) distinct.
 * req_skills[i][j], people[i][j][k] are lowercase English letters.
 * It is guaranteed a sufficient team exists.
 * 
 * 
 */
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int counter = 0;
        for (const string& skill_name : req_skills) {
            _idx[skill_name] = counter;
            counter++;
        }

        for (const vector<string>& skills_has : people) {
            int skill = 0;
            for (const string& skill_name : skills_has) {
                auto it = _idx.find(skill_name);
                if (it == _idx.end()) {
                    continue;
                }
                skill |= 1 << (it->second);
            }
            _people.emplace_back(skill);
        }

        memset(_dp, -1, sizeof(_dp));
        memset(_choose, false, sizeof(_choose));
        dfs(0, 0, _people.size());

        vector<int> ret;
        int status = 0;
        int i = 0;
        while (status != (1 << _idx.size()) - 1 && i < _people.size()) {
            if (_choose[status][i]) {
                status |= _people[i];
                ret.emplace_back(i);
            }
            i++;
        }
        return ret;
    }

private:
    int dfs(int status, int i, int n) {
        if (_dp[status][i] != -1) {
            return _dp[status][i];
        }

        if (status == (1 << _idx.size()) - 1) {
            _dp[status][i] = 0;
            return _dp[status][i];
        }

        if (i == n) {
            _dp[status][i] = 100000;
            return _dp[status][i];
        }

        if (dfs(status | _people[i], i + 1, n) + 1 < dfs(status, i + 1, n)) {
            // choose i
            _dp[status][i] = dfs(status | _people[i], i + 1, n) + 1;
            _choose[status][i] = true;
        } else {
            // or not
            _dp[status][i] = dfs(status, i + 1, n);
            _choose[status][i] = false;
        }

        return _dp[status][i];
    }

    int         _dp[65536][61];
    bool        _choose[65536][61];
    vector<int> _people;
    unordered_map<string, int> _idx;
};