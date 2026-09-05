class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //prefix and suffix
        int n = nums.size();
        vector<int>largest_prefix(n,nums[0]);
        for(int i=1;i<n;i++){
            largest_prefix[i] = max(largest_prefix[i-1],nums[i]);
        }

        vector<int>smallest_suffix(n,nums[n-1]);
        for(int i=n-2;i>=0;i--){
            smallest_suffix[i] = min(smallest_suffix[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(largest_prefix[i]-smallest_suffix[i] <= k) return i;
        }

        return -1;
    }

    /*
    [5,0,1,4] k=3

    larget_prefix => [5,5,5,5]
    smallest_suffix => [0,0,1,4]
    different => [5,5,4,1];
    */
};