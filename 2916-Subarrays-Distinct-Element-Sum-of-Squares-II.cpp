
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                long long distinct = st.size();
                ans = (ans + distinct * distinct) % MOD;
            }
        }

        return ans;
    }
};

