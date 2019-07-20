sum = lambda a, b, c: a + b + c
print(sum(1, 2, 3))
#lambda格式 lambda 参数列表:表达式
def fn(x):
   return lambda y: x + y

a = fn(2)
print(a(3))
