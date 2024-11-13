n = int(input())

def is_prime(n) :
    d = 2
    while d*d <= n :
        if n % d:
            return True
    return False