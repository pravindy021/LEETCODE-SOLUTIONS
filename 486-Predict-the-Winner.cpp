class Solution {
public:
    int dp[21][21][2];

    int solve(int l, int r, vector<int>& nums, int turn) {

        // No elements left
        if (l > r)
            return 0;

        // Return cached result
        if (dp[l][r][turn] != -1)
            return dp[l][r][turn];

        // Player 1 tries to maximize the score
        if (turn == 0) {
            return dp[l][r][turn] = max(
                nums[l] + solve(l + 1, r, nums, 1),
                nums[r] + solve(l, r - 1, nums, 1)
            );
        }

        // Player 2 tries to minimize Player 1's score
        return dp[l][r][turn] = min(
            solve(l + 1, r, nums, 0),
            solve(l, r - 1, nums, 0)
        );
    }

    bool predictTheWinner(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        int sum = 0;

        for (int num : nums)
            sum += num;

        int curr = solve(0, nums.size() - 1, nums, 0);

        // Player 1 wins or ties
        return curr >= (sum - curr);
    }
};