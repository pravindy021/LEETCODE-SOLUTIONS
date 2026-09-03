class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int min_odd = INT_MAX;

        for (int num : nums1)
            if (num & 1)
                min_odd = min(min_odd, num);

        // Already uniform (all even)
        if (min_odd == INT_MAX)
            return true;

        for (int &num : nums1) {
            if (!(num & 1)) {
                num -= min_odd;
                if (num < 1)
                    return false;
            }
        }

        return true;
    }
};