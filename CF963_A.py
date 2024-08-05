#WHAT I LEARNT:
#we are actually applying operations on the even elements, yet in the code we seem to be applying operations on the odd elements.
#This is because we are trying to make the largest odd element the largest element in the array.
#So, we are actually applying operations on the even elements to make the largest odd element the largest element in the array. and we can use this technique to write optimal code


# First, if all elements already have the same parity, we don't need to do perform any operation.

# Next, if the array contains both 𝑒𝑣𝑒𝑛
#  and 𝑜𝑑𝑑
#  numbers. In this case, it is impossible to convert all elements to 𝑒𝑣𝑒𝑛
#  numbers.

# Why?
# If we apply an operation on:

# two 𝑜𝑑𝑑
#  elements, one of them remains 𝑜𝑑𝑑
# .
# two elements of distinct parities, one of them is replaced with their sum, which is an 𝑜𝑑𝑑
#  number.
# This implies even if we want to change an 𝑜𝑑𝑑
#  element to 𝑒𝑣𝑒𝑛
#  number, it fails in both ways possible.

# So we just want to convert all of them to 𝑜𝑑𝑑
#  numbers. Now come the greedy part:

# 𝑒𝑣𝑒𝑛+𝑒𝑣𝑒𝑛=𝑒𝑣𝑒𝑛⟶
#  it doesn't reduce the number of 𝑒𝑣𝑒𝑛
#  elements, so skip it.
# 𝑜𝑑𝑑+𝑜𝑑𝑑=𝑒𝑣𝑒𝑛⟶
#  this creates another 𝑒𝑣𝑒𝑛
#  number, indeed very awful.
# 𝑒𝑣𝑒𝑛+𝑜𝑑𝑑=𝑜𝑑𝑑⟶
#  this is great, but only if the sum replaces the 𝑒𝑣𝑒𝑛
#  one (which means 𝑒𝑣𝑒𝑛<𝑜𝑑𝑑
# ).
# Let's find the largest 𝑜𝑑𝑑
#  element and call it 𝑠
# . Then traverse each 𝑒𝑣𝑒𝑛
#  elements 𝑡
#  in non-decreasing order and apply an operation on 𝑠
#  and 𝑡
# :

# If 𝑡<𝑠
# , 𝑠+𝑡
#  becomes largest odd number. Thus, we set 𝑠:=𝑠+𝑡
# . This reduce the number of even element by 1
# .
# If 𝑡>𝑠
# , before we do this operation, we need to do another on 𝑠
#  and the largest even element to make 𝑠
#  the largest in the array. Note that this case only happens at most once.
# As a result, the answer is the number of even elements (plus 1
#  if the second case occurs).

# Time complexity: 𝑂(𝑛log𝑛)
# .


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    s = -1
    v = []
    for x in a:
        if x%2 == 0:
            v.append(x)
        elif x > s:
            s = x
    v.sort()

    if s == -1 or v == []:
        print(0)
        continue
    
    ans = len(v)
    for t in v:
        if t < s:
            s += t
        else:
            ans += 1
            break

    print(ans)