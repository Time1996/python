a = 's'
b = 'hell'
c = (True and [a] or [b])[0]
print(c)
#由于[a]是一个非空列表,所以它绝不会为假.即使a是0或是''或者其他假值,列表[a]也为真,因为它有一个元素