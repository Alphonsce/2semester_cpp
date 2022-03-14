#include <iostream>
#include <string>

union fu
{
    float f;
    unsigned int u;
};

short unsigned zero_or_one(unsigned k) {
    if ( (k >> 1) << 1 == k )
        return 0;
    return 1;
}

std::string unsigned_to_binary(unsigned int n) {
    std::string reversed_answer;
    for (int i = 0; i < 32; i ++) {
        reversed_answer += char('0' + zero_or_one(n));
        n = n >> 1;
    }
    return std::string(reversed_answer.crbegin(), reversed_answer.crend());
}

int main() {
    fu a;
    std::cin >> a.f;    // записали число в память как float
    std::cout << a.u << std::endl;      // считали из той же ячейки памяти как unsigned
    std::string as_binary = unsigned_to_binary(a.u);
    std::cout << as_binary[0] << ' ';
    for (int i = 1; i < 9; i ++) {
        std::cout << as_binary[i];
    }
    std::cout << ' ';
    for (int i = 9; i < 32; i ++) {
        std::cout << as_binary[i];
    }
    std::cout << std::endl;
    return 0;
}