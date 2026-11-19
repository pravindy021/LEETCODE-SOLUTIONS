class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int k = n - 2;
        int mini = INT_MAX;

        for(int i = 0 ; i + k <= n ; i++){
            mini = min(mini, nums[i+k-1] - nums[i]);
        }

        return mini;
    }
};