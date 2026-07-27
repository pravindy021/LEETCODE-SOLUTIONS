class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        x: int = 0
        y: int = 0
        for num in nums:
            if num > x: x, y = num, x
            elif num > y: y = num
        return (x - 1) * (y - 1)