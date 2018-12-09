def factorial(n):
    result = n
    for i in range(1, n):
        result *= i
    return result

n = int(input("请输入："))
result = factorial(n)
print(result)
