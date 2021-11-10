#include <iostream>

int get_change(int m) {
  //write your code here
  int sum = 0;
  int rem = m;

  if (m > 9){
    rem = m % 10;
    sum = sum + m / 10;
  }
  
  else if (rem > 4){
    rem = rem % 5;
    sum++;
  }

  else if (rem > 0){
    sum = sum + rem / 1;
  }
  
  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
