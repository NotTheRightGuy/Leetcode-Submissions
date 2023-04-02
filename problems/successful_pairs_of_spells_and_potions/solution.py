class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        arr = []
        for spell in spells:
            ratio = math.ceil(success/spell)
            low = 0
            high = len(potions)
            while(low < high):
                mid = low + ((high - low)//2)
                if(potions[mid] >= ratio):
                    high = mid
                else:
                    low = mid+1
            arr.append(len(potions)-low)
        return arr
                