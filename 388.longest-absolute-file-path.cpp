/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 *
 * https://leetcode.com/problems/longest-absolute-file-path/description/
 *
 * algorithms
 * Medium (40.69%)
 * Likes:    535
 * Dislikes: 1194
 * Total Accepted:    78K
 * Total Submissions: 191.2K
 * Testcase Example:  '"dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext"'
 *
 * Suppose we abstract our file system by a string in the following manner:
 * 
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 * 
 * dir
 * ⁠   subdir1
 * ⁠   subdir2
 * ⁠       file.ext
 * 
 * 
 * The directory dir contains an empty sub-directory subdir1 and a
 * sub-directory subdir2 containing a file file.ext.
 * 
 * The string
 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
 * represents:
 * 
 * dir
 * ⁠   subdir1
 * ⁠       file1.ext
 * ⁠       subsubdir1
 * ⁠   subdir2
 * ⁠       subsubdir2
 * ⁠           file2.ext
 * 
 * 
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1
 * contains a file file1.ext and an empty second-level sub-directory
 * subsubdir1. subdir2 contains a second-level sub-directory subsubdir2
 * containing a file file2.ext.
 * 
 * We are interested in finding the longest (number of characters) absolute
 * path to a file within our file system. For example, in the second example
 * above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and
 * its length is 32 (not including the double quotes).
 * 
 * Given a string representing the file system in the above format, return the
 * length of the longest absolute path to file in the abstracted file system.
 * If there is no file in the system, return 0.
 * 
 * Note:
 * 
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * 
 * 
 * 
 * Time complexity required: O(n) where n is the size of the input string.
 * 
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is
 * another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        int max_length = 0;
        vector<string> paths = split(input, '\n');
        stack<int> st;
        int size = 0;
        for (int i = 0; i < paths.size(); ++i) {
            int depth = count(paths[i].begin(), paths[i].end(), '\t');
            while (st.size() > depth) {
                int j = st.top();
                st.pop();
                if (st.empty()) {
                    size = 0;
                } else {
                    size -= 1 + get_filesize(paths[j]);
                }
            }
            if (st.empty()) {
                size = get_filesize(paths[i]);
            } else {
                size += 1 + get_filesize(paths[i]);
            }
            st.push(i);

            cout << paths[i] << " " << size << endl;

            if (paths[i].find('.') != string::npos) {
                max_length = max(max_length, size);
            }
        }
        return max_length;
    }

private:
    vector<string> split(const string& str, char sep) {
        vector<string> ret;
        if (str.empty()) {
            return std::move(ret);
        }

        size_t pos = 0;
        while (pos < str.size()) {
            size_t idx = str.find(sep, pos);

            if (idx == string::npos) {
                ret.emplace_back(str.substr(pos));
                break;
            }

            if (idx - pos > 0) {
                ret.emplace_back(str.substr(pos, idx - pos));
            }

            pos = idx + 1;
        }
        return std::move(ret);
    }

    int get_filesize(const string& file) {
        size_t pos = file.rfind('\t');
        int file_size = 0;
        if (pos == string::npos) {
            file_size = file.size();
        } else {
            file_size = file.size() - pos - 1;
        }
        return file_size;
    }
};
// @lc code=end