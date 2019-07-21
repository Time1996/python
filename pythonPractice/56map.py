lst_1 = [1, 2, 3, 4, 5, 6]
def double_func(x):
    return x * 2
lst_2 = map(double_func, lst_1)
print(list(lst_2))
#map(第一个参数是函数,第二个参数可以是序列,list,tuple)