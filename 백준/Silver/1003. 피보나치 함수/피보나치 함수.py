t = int(input())

def fibonacci(n):
    for i in range(3, n+1):
        zero.append(zero[i-1] + zero[i-2])
        one.append(one[i-1] + one[i-2])
    print(zero[n], one[n])

for _ in range(t):
    zero = [1, 0, 1]
    one = [0, 1, 1]
    fibonacci(int(input()))