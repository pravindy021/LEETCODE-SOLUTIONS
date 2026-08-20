class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int>prefixSum(nums);
        vector<int>suffixSum(nums);
        prefixSum[0] = nums[0];
        int unchanged = 0;
        for(int left = 1;left<n; left++){
            prefixSum[left]+= prefixSum[left-1];
        }
        suffixSum[n-1] = nums[n-1];
        for(int right = n-2;right>=0; right--){
            suffixSum[right]+= suffixSum[right+1];
        }

        for(int i = 0; i<n;i++){
            if(i<(n-1) && prefixSum[i] == suffixSum[i+1]) unchanged++;
            vector<int>prefixSum = nums;
            vector<int>suffixSum = nums;
            prefixSum[i] = k;
            suffixSum[i] = k;
            for(int left = 1;left<n; left++){
                prefixSum[left]+= prefixSum[left-1];
            }
            for(int right = n-2;right>=0; right--){
                suffixSum[right]+= suffixSum[right+1];
            }
            int count = 0;
            for(int i = 0; i<n-1; i++){
                if((prefixSum[i]-suffixSum[i+1]) == 0) count++;
            }
            ans = max(ans, count);
        }
        
        ans = max(ans, unchanged);
        return ans;

    }
};
