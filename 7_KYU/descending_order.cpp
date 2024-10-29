// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/5467e4d82edf8bbf40000155/cpp

#include <iostream>
#include <cinttypes>
#include <string>
#include <algorithm>

uint64_t descendingOrder(uint64_t a) {
  std::string str_a = std::to_string(a);
  std::sort(str_a.begin(), str_a.end(), std::greater<char>());
  return std::stoull(str_a);
}