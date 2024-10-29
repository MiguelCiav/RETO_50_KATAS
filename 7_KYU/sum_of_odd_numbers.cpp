// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/55fd2d567d94ac3bc9000064/

#include <iostream>

long long rowSumOddNumbers(unsigned n){
  long long result = 1;
  long long sum_number;
  for(long long i = 1, j = 0; i <= n; i++, j++) {
    result = (i*j) + 1;
  }
  sum_number = result + 2;
  for(long long i = 0; i < n - 1; i++) {
    result += sum_number;
    sum_number += 2;
  }
  return result;
}

int main() {
    std::cout << rowSumOddNumbers(42) << std::endl; // Debería devolver: 21
    return 0;
}