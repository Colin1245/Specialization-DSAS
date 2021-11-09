#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int fibonacci_sum_fast(long long n, long sum = 0)
{
    // S(n) = F(n+2) – 1 
    return (get_fibonacci_huge_fast(n + 2, 10) - 1) % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long F_to = 0;
    long long F_from = 0;
    F_from = fibonacci_sum_fast(from - 1);
    F_to = fibonacci_sum_fast(to);
    return F_to - F_from;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    int sum = get_fibonacci_partial_sum_fast(from, to);
    int value = sum < 0 ? (sum + 10) : sum;
    std::cout << value << std::endl;

    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
