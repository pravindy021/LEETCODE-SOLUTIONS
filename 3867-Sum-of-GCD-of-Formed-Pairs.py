from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)

        prefix_gcd = []

        prefix_max = 0

        for x in nums:
            prefix_max = max(prefix_max, x)
            prefix_gcd.append(gcd(x, prefix_max))

        prefix_gcd.sort()

        ans = 0

        left = 0
        right = n - 1

        while left < right:
            ans += gcd(prefix_gcd[left], prefix_gcd[right])
            left += 1
            right -= 1

        return ans
        