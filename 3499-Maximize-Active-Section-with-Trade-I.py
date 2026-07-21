class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        o=s.count('1')
        aug='1'+s+'1'
        a=[]
        i=0
        while i<len(aug):
            j=i
            while j<len(aug) and aug[j]==aug[i]:
                j+=1
            a.append((aug[i],j-i))
            i=j
        sol=o
        for i in range(1, len(a) - 1):
            if (a[i][0] == '1' and a[i - 1][0] == '0' and a[i + 1][0] == '0'):
                g = a[i - 1][1] + a[i + 1][1]
                sol=max(sol, o + g)
        return sol

        