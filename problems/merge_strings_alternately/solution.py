class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = []
        counter = 0
        while(counter < len(word1)*2 and counter < len(word2)*2):
            if counter % 2 == 0:
                ans.append(word1[counter//2])
            else:
                ans.append(word2[counter//2])
            counter += 1
        if counter < len(word1)*2:
            ans.append(word1[counter//2 : ])
        else:
            ans.append(word2[counter//2 : ])
        return ''.join(ans)