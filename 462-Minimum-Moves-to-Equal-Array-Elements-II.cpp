class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n=nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int median=nums[n/2];// median or upper median
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=abs(nums[i]-median);
        return sum;
    }
};