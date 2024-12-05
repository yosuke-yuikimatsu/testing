#include <vector>
#include <iostream>

long long fib(int n) {
    std::vector<long long> fib( n + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 0; i <= n; ++i) {
        fib[i] = fib[i-1] + fib[i+1];
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n);
}