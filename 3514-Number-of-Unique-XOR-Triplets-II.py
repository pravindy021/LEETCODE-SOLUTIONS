class Solution:
    def uniqueXorTriplets(self, a: List[int]) -> int:
        f = lambda a,b:{*starmap(xor,product(a,b))}
        return len(f(a:={*a},f(a,a)))
        