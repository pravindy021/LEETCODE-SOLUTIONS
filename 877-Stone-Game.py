class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        """
        return True
        """
        n = len(piles)
        dp = [0] * n
        for l in range(n - 1, -1, - 1):
            for r in range(l, n):
                turn = (l + r) % 2
                left = turn * piles[l]
                right = turn * piles[r]
                if l == r:
                    dp[r] = 0
                else:
                    if turn:
                        dp[r] = max(piles[l] + dp[r], piles[r] + dp[r - 1])
                    else:
                        dp[r] = min(dp[r], dp[r - 1])

        return dp[n - 1] > sum(piles) - dp[n - 1]
        