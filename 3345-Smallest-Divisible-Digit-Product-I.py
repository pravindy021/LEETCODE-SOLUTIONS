class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n, n + 1000):
            x = i
            temp = 1
            while x > 0:
                temp *= x % 10
                x //= 10
            if temp % t == 0:
                return i
        