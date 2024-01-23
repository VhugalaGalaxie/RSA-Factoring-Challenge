#!/usr/bin/python3
import math

def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    sqrt_n = math.isqrt(n)
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    return True

def factorize(n):
    if is_prime(n):
        return [n, 1]
    for i in range(3, math.isqrt(n) + 1, 2):
        if n % i == 0:
            p = i
            q = n // i
            return [p, q]
    return []

n = 123456789012345
p, q = factorize(n)
print(f"p = {p}, q = {q}")
