class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;
        for (auto n : arr1) {
            for (auto m : arr2) {
                if (abs(m-n) <= d) {
                    goto end;
                }
            }
            ret++;
            end:
        }
        return ret;
    }
};