#include <iostream>
#include <cassert>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    std::vector<long long> fib{0, 1};

    for (int i = 2; i <= n; i++){
        int value = fib.at(i - 2) % 10 + fib.at(i - 1) % 10;
        fib.push_back(value);
    }

    if (n == 0){return 0;}
    else if (n == 1){return 1;}
    else{return (fib.back()) % 10;} 
}

void test_solution() {
    assert(get_fibonacci_last_digit_naive(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n)
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}

int main() {
    int n;
    std::cin >> n;
    // test_solution();
    // std::cout << get_fibonacci_last_digit_naive(n) << std::endl;
    std::cout << get_fibonacci_last_digit_fast(n) << std::endl;
    }
