#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric> 

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();

  // write your code here
  vector<double> valweight = {0.0, 0.0, 0.0};
  for (int i = 0; i < n; i++){
    valweight.at(i) = values.at(i) / weights.at(i);
  }

  // for (auto elem : valweight){
  //   std::cout << elem << " ";
  // }

  vector<int> indice(n);
  std::iota(indice.begin(),indice.end(),0); //Initializing
  std::sort(indice.begin(),indice.end(), [&](int i,int j){return valweight[i]<valweight[j];});

  // for (auto elem : indice){
  //   std::cout << elem << " ";
  // }

  while (capacity - weights.at(indice.back()) > 0){
    value += values.at(indice.back());
    capacity -= weights.at(indice.back());
    indice.pop_back();
    // std::cout << capacity << " " << value << std::endl;
  }
  
  value += (capacity / weights.at(indice.back())) * values.at(indice.back());

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
