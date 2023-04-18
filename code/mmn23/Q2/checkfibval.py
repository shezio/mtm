import sys

def fibonacci(n):
    if n == 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [0, 1]
    else:
        seq = [0, 1]
        while len(seq) < n:
            seq.append(seq[-1] + seq[-2])
        return seq

# calling the function and printing the last value in the sequence
fib_seq = fibonacci(int(sys.argv[1]))
print(fib_seq[-1],fib_seq[-2],fib_seq[-3])  # output: 34