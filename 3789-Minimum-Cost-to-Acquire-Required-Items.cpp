class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        long long ans = 0;
        if (cost1 + cost2 >= costBoth) {
            long long mn = min(need1, need2);
            need1 -= mn;
            need2 -= mn;
            ans += (mn * costBoth);
        }
        if (cost1 >= costBoth)
            ans += (1LL * need1 * costBoth), need1 = 0;
        if (cost2 >= costBoth)
            ans += (1LL * need2 * costBoth), need2 = 0;
        ans += (1LL * need1 * cost1);
        ans += (1LL * need2 * cost2);
        return ans;
    }
};