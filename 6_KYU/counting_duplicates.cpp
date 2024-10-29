// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1/train/cpp

#include <string>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>

std::size_t duplicateCount(const std::string& in) {
    std::unordered_set <char> seen;
    std::string str = in;
    std::transform(str.begin(),str.end(),str.begin(),tolower);
    for(auto c : str) {
        if(std::count(str.begin(),str.end(),c) > 1) {
            seen.insert(c);
        }
    }
    return seen.size();
}

int main() {
    std::cout << duplicateCount("abcde") << std::endl; // Output: 0
    std::cout << duplicateCount("aabbcde") << std::endl; // Output: 2
    std::cout << duplicateCount("Indivisibility") << std::endl; // Output: 2
    std::cout << duplicateCount("aA11") << std::endl; // Output: 2
    std::cout << duplicateCount("abcABC123") << std::endl; // Output: 3
    return 0;
}