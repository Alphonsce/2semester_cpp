#include <iostream>

using namespace std;

long long unsigned get_sum(long long unsigned n) {
    long long int total = -n, p = 1;

    while (p <= n) {
        total += n / p;
        p *= 2;
    }

    return total;
}

int main() {
    long long unsigned n;
    cin >> n;
    cout << get_sum(n) << endl;
}