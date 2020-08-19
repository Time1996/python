#-*-coding:utf-8-*-0
import re
import requests
from lxml import etree

header={"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36"}


def get_url(url):
    html = requests.get(url, headers=header)
    data = etree.HTML(html.text)
    return data
# pn = data.xpath('//div[@class="content"]/div[@class="info"]//text()')
# with open("D://test.txt", 'w', encoding='utf-8') as f:
#     for i in pn:
#         print(i)
#         f.write(i)
cnt = 1
with open('test.txt', 'w', encoding="utf-8") as f:
    for i in range(0,10):
        url1 = f'https://movie.douban.com/top250?start={i*25}&filter='
        name = get_url(url1).xpath('//div[@class="hd"]/a/span[@class = "title"]//text()')
        for j in range(0,len(name)-1):
            name[j] = (re.sub(r' \/ ', '00', name[j]))#经过处理 发现斜杠前面不是普通的空格,通过复制name[j]里的内容才匹配到,00是标记,为了之后过滤掉别名,因为别名和分数长度不一样
            # print(name[j])
            # print(j)
        score = get_url(url1).xpath('//div[@class = "star"]/span[@class = "rating_num"]//text()')
        # print(name)
        z = 0
        for k in range(0, len(name)):
            try:
                names = name[k]
                if names[0] == '0' and names[1] == '0': continue
                scores = score[z]
                z+=1
                f.write(f'Top{cnt} ')
                f.write(names)#content里是二进制数据 适合保存图片,文件,text适合保存文本
                f.write(' ')
                f.write(scores+'分')
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