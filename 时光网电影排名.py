#-*-coding:utf-8-*-0
import re
import requests
from lxml import etree

header={"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36"}


def get_url(url):
    html = requests.get(url,headers=header)
    data = etree.HTML(html.text)
    return data
# pn = data.xpath('//div[@class="content"]/div[@class="info"]//text()')
# with open("D://test.txt", 'w', encoding='utf-8') as f:
#     for i in pn:
#         print(i)
#         f.write(i)
cnt = 1
with open('test.txt', 'w', encoding="utf-8") as f:
    for i in range(1,10+1):
        if i>=2:
            url1 = f'http://www.mtime.com/top/movie/top100/index-{i}.html'
        else :
            url1 = f'http://www.mtime.com/top/movie/top100/'
        print(i)
        name = get_url(url1).xpath('//h2[@class = "px14 pb6"]/a//text()')
        score = get_url(url1).xpath('//div[@class = "mov_point"]/b[@class = "point"]/span[@class = "total"]//text()')
        #小数点
        score1 = get_url(url1).xpath('//div[@class = "mov_point"]/b[@class = "point"]/span[@class = "total2"]//text()')
        for j in range(0, len(name)):
            try:
                names = name[j]
                scores = score[j]
                scores1 = score1[j]
                f.write(names)#content里是二进制数据 适合保存图片,文件,text适合保存文本
                f.write(' ')
                f.write(scores+scores1+'分')
                f.write('\r\n')
                cnt += 1
                print(cnt)
            except:
                print("抛出异常!")

# with open("D://test.txt") as f:
#     print(f.read())
# def get_hd
# uid(url):
#     html = requests.get(url,headers=header).text
#     data = etree.HTML(html)
#     pn = data.xpath('//ul[@class="bangumi-list clearfix"]/li[@class="bangumi-item"]//text()')
#     print(pn)