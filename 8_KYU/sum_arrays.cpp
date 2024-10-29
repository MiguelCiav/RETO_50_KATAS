// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/53dc54212259ed3d4f00071c/train/cpp

#include <vector>
#include <numeric>
#include <iostream>

int sum(std::vector<int> nums) {
  return std::accumulate(nums.begin(),nums.end(),0);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int sum_of_nums = sum(nums);
    std::cout << "Sum of the numbers: " << sum_of_nums << std::endl;
    return 0;
}
