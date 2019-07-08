from random import  randint

#读取文件中的成绩数据
f = open('c:/Users/Administrator/PycharmProjects/untitled/game.txt')
score = f.read().split()
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
print('你已经完了%d次，最少%d轮猜出答案，平均%d轮猜出答案' % (game_times, min_times, avg_times))

num = randint(1, 100)
print('Guess what I think?')
bingo = False
while bingo == False:
    answer = input()
    answer = int(answer)
    if answer < num:
        print('too small!')
    if answer > num:
        print('too big!')
    if answer == num:
        print('BINGO!')
        bingo == True