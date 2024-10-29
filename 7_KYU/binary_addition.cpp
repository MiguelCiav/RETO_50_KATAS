// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/551f37452ff852b7bd000139/cpp

#include <cstdint>
#include <bitset>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
  uint64_t c = a + b;
  if(c == 0) {
    return "0";
  }
  std::string result = std::bitset<64>(c).to_string();
  result.erase(0, result.find_first_not_of('0'));
  return result;
}