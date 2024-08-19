# WHAT I LEARNT:
# was not familiar with xor problems at the time of solving this problem

# Note that (𝑎1⊕𝑥)⊕(𝑎2⊕𝑥)⊕...
#  equals 𝑎1⊕𝑎2⊕…⊕𝑎𝑛
#  if 𝑛
#  is even, or 𝑎1⊕𝑎2⊕…⊕𝑎𝑛⊕𝑥
#  if 𝑛
#  is odd. Then, if the length of the array is odd, you must print ⊕
#  of the whole array. And if the length is even, we can't change the value of the expression with our operation. It turns out that if ⊕
#  of the whole array is 0
# , we can output any number, but otherwise there is no answer.

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    xor = 0
    for x in a:
        xor ^= x
    if xor == 0:
        print(0)
    else:
        if n % 2 == 1:
            print(xor)
        else:
            print(-1)