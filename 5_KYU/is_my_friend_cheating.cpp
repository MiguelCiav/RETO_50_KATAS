// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/5547cc7dcad755e480000004/cpp

#include <vector>

using namespace std;

class RemovedNumbers
{
public:
	static vector<vector<long long>> removNb(long long n) {
    vector<vector<long long>> result;
    long long sum = (n*(n+1))/2;
    for(long long a = 1; a <= n; a++) {
        long long b = (sum-a)/(a+1);
        if(b <= n & a*b == sum - a - b){
            result.push_back({a, b});
        }
    }
    return result;
  };
};