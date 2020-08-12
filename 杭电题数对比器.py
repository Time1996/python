#-*-coding:utf-8-*-0
import re
import requests
from lxml import etree

header={'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36'}
url1 = 'http://acm.hdu.edu.cn/userstatus.php?user=Endeavour01'  #user=用户名
url2 = 'http://acm.hdu.edu.cn/userstatus.php?user=yf584299804'   #user=用户名
def get_hduid(url):
    html = requests.get(url,headers=header).text
    # print(html)
    data = etree.HTML(html)
    # pn = data.xpath('//p[@class="footer_link"]/font[@size="3"]/a[@href]//text()')
    id = data.xpath('//p[@align="left"]/script[@language="javascript"]//text()')
    # print(len(id),id)
    a=id[0].split(',')
    b=[]
    for i in a:
        b.append(re.findall(r'\d{4}',i))
    return b
x = get_hduid(url1)
y = get_hduid(url2)
print(x)
print(y)
z=[]
for i in x:#y没做的x题
    if i not in y:
        z.append(i)
cnt=0
use1=input()
use2=input()
print(use2 + "没做"+use1 + "的题有"+str(len(z))+"道:")
for i in z:
    if cnt%10==0:
        print()
    print(i,end='')
    cnt += 1
print()
w=[]
for i in y:#y没做的x题
    if i not in x:
        w.append(i)
cnt=0
print(use1 + "没做"+use2 + "的题有"+str(len(w))+"道:")
for i in w:
    if cnt%10==0:
        print()
    print(i,end='')
    cnt += 1