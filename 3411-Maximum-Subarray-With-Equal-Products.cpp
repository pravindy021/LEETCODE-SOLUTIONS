class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++){
            long long prod = nums[i], LCM = nums[i], GCD = nums[i];

            for(int j = i + 1; j < n; j++){
                prod = prod * nums[j];
                LCM = lcm(LCM, nums[j]);
                GCD = gcd(GCD, nums[j]);

                if(prod > LCM * GCD) break;
                if(prod == LCM * GCD) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};