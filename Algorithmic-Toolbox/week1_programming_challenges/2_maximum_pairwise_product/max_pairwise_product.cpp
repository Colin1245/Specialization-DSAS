#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();
    
    int max_index1 = -1;
    for (int i = 0; i < n; i++){
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])){
            max_index1 = i;
        }
    }
    
    int max_index2 = -1;
    for (int j = 0; j < n; j++){
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
            max_index2 = j;
        }
    }
    // std::cout << max_index1 << " " << max_index2 << std::endl;
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    // int n;
    // std::cin >> n;
    // std::vector<int> numbers(n);
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> numbers[i];
    // }

    // std::cout << MaxPairwiseProductFast(numbers) << "\n";

    // long long result =  MaxPairwiseProductFast(std::vector<int>(100000,0));
    // std::cout << result << std::endl;

    // while (true)
    // {
    //     int n = rand() % 1000 + 2;
    //     std::cout << n << std::endl;
    //     std::vector<int> a;
    //     for (int i = 0; i < n; i++)
    //     {
    //         a.push_back(rand() % 100000);
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         std::cout << a[i] << " ";
    //     }
    //     std::cout << std::endl;
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 =  MaxPairwiseProductFast(a);
    //     if (res1 != res2){
    //         std::cout << "Wrong answer: " << res1 << " " << res2 << std::endl;
    //         break;
    //     }
    //     else{
    //         std::cout << "OK" << std::endl;
    //     }    
    // }
        
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result =  MaxPairwiseProductFast(numbers);
    std::cout << result << std::endl; 
    
    return 0;
}
