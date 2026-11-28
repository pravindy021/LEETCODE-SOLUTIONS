class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = INT_MAX;
        map<int, long long> mp;
        for (auto &x : items) {
            int category = x[0];
            int price = x[1];
            mp[category]++;
            mini = min(mini, price);
        }
        for (auto &[cat, cnt] : mp) {
            for (int i = 2 * cat; i <= n; i += cat) {
                if (mp.count(i)) {
                    mp[cat] += mp[i];
                }
            }
        }
        map<int, long long> pair_offers;
        for (auto &item : items) {
            int cat = item[0];
            int price = item[1];
            if (mp[cat] > 1) {
                pair_offers[price] += (mp[cat] - 1);
            }
        }
        long long ans = 0;
        long long rem_budget = budget;
        for (auto &[price, cnt] : pair_offers) {
            if (price > 2LL * mini || price > rem_budget) {
                break;
            }
            long long can_buy = min(cnt, rem_budget / price);
            ans += 2 * can_buy;
            rem_budget -= can_buy * price;
        }
        ans += rem_budget / mini;
        return ans;
    }
};