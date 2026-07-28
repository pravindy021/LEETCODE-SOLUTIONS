class Solution:
    def smallestPalindrome(self, s: str) -> str:
        freq = {}

        for i in s:
            freq[i] = freq.get(i, 0) + 1

        left = ""
        middle = ""

        for ch in sorted(freq):
            left += ch * (freq[ch] // 2)

            if freq[ch] % 2 == 1:
                middle = ch

        right = left[::-1]

        return left + middle + right
        