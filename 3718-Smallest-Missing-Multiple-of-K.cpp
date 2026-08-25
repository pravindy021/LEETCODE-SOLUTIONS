class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;

        for (int x : nums) {
            mp[x] = true;
        }

        int i = 1;

        while (mp.count(k * i)) {
            i++;
        }

        return k * i;
    }
};