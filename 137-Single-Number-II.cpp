class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones{};
        int twos{};

        for (int val : nums) {
            ones = (ones ^ val) & ~twos;
            twos = (twos ^ val) & ~ones;
        }

        return ones;
    }
};