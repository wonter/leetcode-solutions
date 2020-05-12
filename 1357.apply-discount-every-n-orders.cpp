/*
 * @lc app=leetcode id=1357 lang=cpp
 *
 * [1357] Apply Discount Every n Orders
 */

// @lc code=start
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) :
            _n(n), _counter(0), _discount(discount) {
        for (int i = 0; i < products.size(); ++i) {
            _prices[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        int discount = 0;
        double bill = 0.0;

        ++_counter;
        if (_counter == _n) {
            _counter = 0;
            discount = _discount;
        }

        for (int i = 0; i < product.size(); ++i) {
            bill += _prices[product[i]] * amount[i];
        }

        return bill - (discount * bill) / 100;
    }

private:
    int _n;
    int _counter;
    int _discount;
    unordered_map<int, int> _prices;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
// @lc code=end

