import random
secret = random.randint(1,10)

print('------test1------')
temp = input("你猜猜我想的是啥：")
guess = int(temp)
while guess != secret:
    if guess > secret:
        print("大了大了！")
    else:
        print("小了小了！")
    temp = input("猜错了！请重新输入：")
    guess = int(temp)
print("猜对了！")
print("猜对了也没有奖励！")
print("游戏结束！")
