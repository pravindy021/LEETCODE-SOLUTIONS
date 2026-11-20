class Solution {
public:
    int maxSelectedElementsUtil(int idx, int inc, vector<vector<int>>& dp, vector<int>& nums)
    {
        int n = nums.size();
        if(idx >= n)
            return 0;
        if(dp[idx][inc] != -1)
            return dp[idx][inc];
        int withInc = 0, withoutInc = 0;
        int currVal = nums[idx] + inc;
        
        auto itInc = lower_bound(nums.begin() + idx + 1, nums.end(), currVal);
        if (itInc != nums.end() && *itInc == currVal) {
            int i = int(itInc - nums.begin());
            withInc = max(withInc, maxSelectedElementsUtil(i, 1, dp, nums));
        }
        
        auto itNoInc = lower_bound(nums.begin() + idx + 1, nums.end(), currVal+1);
        if (itNoInc != nums.end() && *itNoInc == currVal+1) {
            int i = int(itNoInc - nums.begin());
            withoutInc = max(withoutInc, maxSelectedElementsUtil(i, 0, dp, nums));
        }
        return dp[idx][inc] = 1 + max(withoutInc, withInc);
    }
    int maxSelectedElements(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(n, vector<int>(2, -1));
        int maxRes = 1;
        for(int i = 0; i < n; i++)
        {
            maxSelectedElementsUtil(i, 0, dp, nums);
            maxSelectedElementsUtil(i, 1, dp, nums);
        }
        for(int i = 0; i < n; i++)
            maxRes = max(max(dp[i][0], dp[i][1]), maxRes);
        return maxRes;
    }
};