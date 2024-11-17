n = int(input("Enter your number here:"))

def is_prime(n) :
    d = 2
    while d*d <= n:
        if n % d == 0:
            return True
    return False