import re
text = 'site sea sue sweet see see see sseee loses'
m = re.findall(r'\bs\S*e\b', text)#r表示raw不对字符串进行转义,不用的话\会转义
if m:
    print(m)
else:
    print('not match')
#正则表达式强大作用初窥