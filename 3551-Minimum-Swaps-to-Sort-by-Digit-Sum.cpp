
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if (sumA == sumB)
                return a < b;

            return sumA < sumB;
        });

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i])
                continue;

            int j = pos[sorted[i]];

            pos[nums[i]] = j;
            pos[nums[j]] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};
