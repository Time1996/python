#-*-coding:utf-8-*-0
import re
import requests
from lxml import etree

header={"Mozilla/5.0" : "(Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36"}


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
for i in range(1,121+1):
    url1 = f'http://pic.yxdown.com/list/0_0_{i}.html'
    pn = get_url(url1).xpath('//div[@class = "cbmiddle"]/a/img/@src')
    for j in pn:
        try:
            with open(f'test1(done)\{cnt}.jpg', 'wb') as f:
                pic = requests.get(j)
                f.write(pic.content)#content里是二进制数据 适合保存图片,文件,text适合保存文本
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