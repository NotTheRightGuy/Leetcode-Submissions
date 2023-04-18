class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        sol = []
        maxVal = max(candies)
        ans = []
        for candy in candies:
            ans.append(candy + extraCandies >= maxVal)
        return ans 