from functools import reduce
lst = range(1, 101)
def add(x, y):
    return x + y
print(reduce(add, lst))
#reduce用法与map相似，第一个参数是作用在序列上的方法,第二个参数是被作用的序列.