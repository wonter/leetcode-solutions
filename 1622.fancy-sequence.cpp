/*
 * @lc app=leetcode id=1622 lang=cpp
 *
 * [1622] Fancy Sequence
 */

// @lc code=start
constexpr int MOD = 1000000007;
class Fancy {
public:
    Fancy() {
        
    }
    
    void append(int val) {
        nums.emplace_back(val);
        nums.back() = (nums.back() - add + MOD) % MOD;
        nums.back() = (nums.back() * mod_inv(mul, MOD)) % MOD;
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        add = (add * m) % MOD;
        mul = (mul * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) {
            return -1;
        }

        return (nums[idx] * mul + add) % MOD;
    }

private:
    long long mod_pow(long long a, long long b, long long p) {
        long long ans = 1;
        a %= p;
        while(b > 0) {
            if(b & 1)  {
                ans = ans * a % p;
            }
            a = a * a % p;
            b >>= 1;
        }
        return ans;
    }

    long long mod_inv(long long a, long long p) {
        return mod_pow(a, p-2, p);
    }

    long long add{0};
    long long mul{1};
    vector<long long> nums;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
// @lc code=end

