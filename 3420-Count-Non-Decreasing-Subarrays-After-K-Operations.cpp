class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int cnt = 1;

            
            while (!dq.empty() && dq.back().first < num) {

                auto [val, c] = dq.back();
                dq.pop_back();

                cost += 1LL * (num - val) * c;

                cnt += c;
            }

            dq.push_back({num, cnt});

           
            while (cost > k) {

                auto [val, c] = dq.front();
                dq.pop_front();

                cost -= val - nums[j];
                j--;

                if (c > 1) {
                    dq.push_front({val, c - 1});
                }
            }

            
            ans += j - i + 1;
        }

        return ans;
    }
};

