class Solution:
    def fizzBuzz(self, n:int) -> list[str]:
        li = []
        for i in range(1,n+1):
            var = ""
            if(i % 3 == 0):
                var += "Fizz"
            if(i % 5 == 0):
                var += "Buzz"
            li.append(var) if len(var) != 0 else li.append(str(i))
        return li
