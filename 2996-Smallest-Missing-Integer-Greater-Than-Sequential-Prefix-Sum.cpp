class Solution {
public:

    int findnum(int x, vector<int>& nums) {

        int n = x;

        for(int i = 0; i < nums.size(); i++) {

            if(n == nums[i]) {
                n++;
                i = -1;
            }
        }

        return n;
    }

    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int sum = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        int ans = findnum(sum, nums);

        return ans;
    }
};