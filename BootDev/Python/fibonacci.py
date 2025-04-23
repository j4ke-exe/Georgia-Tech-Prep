def fib(n):
    if n < 0: return - 1
    if n == 0: return 0
    if n == 1: return 1

    a = 0
    b = 1

    for i in range(2, n + 1):
        next = a + b
        a = b
        b = next
    return b
