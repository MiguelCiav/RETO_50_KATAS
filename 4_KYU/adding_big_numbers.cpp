#include <iostream>
#include <string>

typedef unsigned long long ull;

std::string add(const std::string& a, const std::string& b) {
    ull size = std::max(a.length(), b.length()) + 1;
    ull j = a.length() - 1, k = b.length() - 1;
    bool j_finished = false, k_finished = false;
    int x, y, z, carry = 0;
    std::string result;

    if(a.length() == 0) {
        j_finished = true;
    }
    if(b.length() == 0) {
        k_finished = true;
    }

    for (ull i = size - 1;; --i) {
        if(j_finished){
            x = 0;
        } else if (j == 0) {
            j_finished = true;
            x = a[j] - '0';
        } else {
            x = a[j] - '0';
        }
        if(k_finished){
            y = 0;
        } else if (k == 0) {
            k_finished = true;
            y = b[k] - '0';
        } else {
            y = b[k] - '0';
        }
        z = x + y + carry;
        carry = z / 10;
        result.insert(result.begin(), z % 10 + '0');
        --k;
        --j;
        if(i == 0) {
            break;
        }
    }

    int i = 0; 
    while (size != 1 && result[i] == '0') {
        i++;
        --size;
    }
    result.erase(0, i);
    return result;
}

int main () {
    std::cout << add("100000000000000000000115600000000000000000000000000000000000000000000000000000000", "1516161632513261261261256124126126121") << std::endl; // Output: 579
    return 0;
}