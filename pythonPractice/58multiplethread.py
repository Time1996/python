import urllib.request, time, _thread

time_start = time.time()
data = []
def get_content(i):
    id = 1764796 + i
    url ='https://api.douban.com/v2/movie/subject/%d' % id
    headers = {'User-Agent': 'Mozilla/5.0(windows NT 6.1; WOW64; rv:23.0) Gecko/20100101 Firefox/23.0'}
    req = urllib.request.Request(url=url,headers=headers)
    d = urllib.request.urlopen(req).read()
    data.append(d)
    print(i, time.time() - time_start)
    return d

print('data:', len(data))

for i in range(30):
    print('request movie:', i)
    _thread.start_new_thread(get_content(i,))

raw_input('press ENTER to exit...\n')