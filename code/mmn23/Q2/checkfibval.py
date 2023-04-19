import sys

def fibonacci(n):
    if n == 0:
        return [1]
    elif n == 1:
        return [1]
    elif n == 2:
        return [1, 1]
    else:
        seq = [1, 1]
        while len(seq) < n:
            seq.append(seq[-1] + seq[-2])
        return seq

# calling the function and printing the last value in the sequence
fib_seq = fibonacci(int(sys.argv[1]))
#print(' '.join(map(str,list(reversed(fib_seq)))))  # output: 3
print(fib_seq[-1])
#print(fib_seq)  # output: 34