class Solution:
    def countBits(self, n: int) -> List[int]:
        if n==0:
            return [0]
        li = [0, 1]
        for i in range(2, n+1):
            power_2 = floor(log2(i))
            li.append(li[i - (2 ** power_2)] + 1)
        return li