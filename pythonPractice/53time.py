import time
starttime = time.time()
time.sleep(5)#time.sleep是个很有用的方法 在爬虫中抓取网页 适当让程序sleep一下,可以减少短时间内的请求,提高请求的成功率.
print('start:%f' % starttime)
for i in range(10):
    print(i)
endtime = time.time()
print('endtime:%f' % endtime)
print('total time:%f' % (endtime - starttime))