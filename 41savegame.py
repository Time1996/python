from random import  randint

name = raw_input('请输入你的名字:') #输入玩家名字

#读取文件中的成绩数据
f = open('c:/Users/Administrator/PycharmProjects/untitled/game.txt')
lines = f.readlines()
f.close()

scores = {} #初始化一个空字典
for l in lines:
    s = l.split() #把每一行的数据拆分成List
    scores[s[0]] = s[1:] #第一项作为key,剩下的作为value
score = scores.get(name) #查找当前玩家的数据
if score is None: #如果没找到
    score = [0, 0, 0] #初始化数据
#分别存入变量中
game_times = int(score[0])
min_times = int(score[1])
total_times = int(score[2])
#计算游戏的平均轮数,注意浮点数和避免除零错误
if game_times > 0:
    avg_times = float(total_times) / game_times
else:
    avg_times = 0
#输出成绩信息,平均轮数保留2位小数
print('你已经玩了%d次，最少%d轮猜出答案，平均%d轮猜出答案' % (game_times, min_times, avg_times))

num = randint(1, 100)
times = 0 #记录本次游戏轮数
print('Guess what I think?')
bingo = False
while bingo == False:
    times += 1
    answer = input()
    answer = int(answer)
    if answer < num:
        print('too small!')
    if answer > num:
        print('too big!')
    if answer == num:
        print('BINGO!')
        bingo == True

#如果是第一次玩,或者轮数比最小轮数少,则更新最小轮数
if game_times == 0 or times < min_times:
    min_times = times
total_times += times #总游戏轮数增加
game_times += 1 #游戏次数增加

#把成绩更新到对应的玩家数据中
#家str转成字符串,为后面的格式化作准备
scores[name] = [str(game_times), str(min_times), str(total_times)]
result = '' #初始化一个空字符串,用来存储数据
for n in scores:
    #把成绩按照“name game_times min_times total_times”格式化
    #结尾要加上\n换行
    line = n + ' ' + ' '.join(scores[n]) + '\n'
    result += line #添加到result中
f = open('c:/Users/Administrator/PycharmProjects/untitled/game.txt', 'w')
f.write(result)
f.close()