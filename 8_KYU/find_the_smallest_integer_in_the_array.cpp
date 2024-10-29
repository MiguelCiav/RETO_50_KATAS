// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/55a2d7ebe362935a210000b2/cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int findSmallest(vector <int> list) {
  return *min_element(list.begin(),list.end());
}

int main () {
    vector<int> numbers = {1, 2, 3, 4, 5};
    cout << "The smallest number in the list is: " << findSmallest(numbers) << endl;
    return 0;
}