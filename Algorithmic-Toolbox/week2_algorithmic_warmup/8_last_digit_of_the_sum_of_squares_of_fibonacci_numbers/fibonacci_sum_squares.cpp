#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long pisano(long long m){
    long long res = 0;    
    long long a = 0, b = 1, c = a + b;

    for (long long i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
        {
            res = i + 1;
        }
        
    }
    // std::cout << "res: " << res << std::endl;
    return res;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long pisano_period = pisano(m);
    n = n % pisano_period;

    std::vector<long long> fib{0, 1};

    for (int i = 2; i <= n; i++){
        long long value = fib.at(i - 2) % m + fib.at(i - 1) % m;
        fib.push_back(value);
    }

    if (n == 0){return 0;}
    else if (n == 1){return 1;}
    else{return (fib.back()) % m;}    

}

// For Sum of Squares of Fibonacci Numbers, (F0^2 + ... + Fn^2) = Fn * Fn+1 = Fn * (Fn-1 + Fn)
int fibonacci_sum_squares_fast(long long n) {
    int Fn = get_fibonacci_huge_fast(n, 10);
    int Fn_1 = get_fibonacci_huge_fast(n - 1, 10);
    int result = (Fn * (Fn + Fn_1)) % 10;
    int value = result < 0 ? (result + 10) : result;
    return value;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << get_fibonacci_last_digit_fast(n) << std::endl;
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;
}
