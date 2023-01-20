class Solution:

    def duplicateZeros(self, arr: list[int]) -> None:
        arr1 = []
        for i in arr:
            arr1.append(i)
            if i == 0:
                arr1.append(0)
        for i in range(len(arr)):
            arr[i] = arr1[i]
        
