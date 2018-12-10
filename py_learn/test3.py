file_name = input("请输入需要打开的文件名：")
f = open(file_name)
for each_line in f:
    print(each_line)
