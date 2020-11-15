#!/usr/bin/env python3
import random
N = 200000 # random.randint(1, 200000)
Q = 200000 # random.randint(1, 200000)
print(N, Q)
for _ in range(N):
    C = random.randint(1, N)
    print(C)

for _ in range(Q):
    q = random.randint(1, 2)
    a = random.randint(1, N)
    b = random.randint(1, N)
    print(q, a, b)