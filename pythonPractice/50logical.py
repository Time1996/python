import re
text = 'Hi, I am Shirley Hilton. I am his wife.'
m = re.findall(r'\b[Hh]i', text)
if m:
    print(m)
else:
    print('not match')
#正则表达式强大作用初窥