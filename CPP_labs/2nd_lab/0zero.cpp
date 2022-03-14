#include <iostream>
#include <string>

std::string stupid_unsigned_to_binary(unsigned n) {
    std::string reversed_answer;
    for (int i = 0; i < 32; i ++) {
        reversed_answer += char('0' + n % 2);
        n = n >> 1;
    }
    
    return std::string(reversed_answer.crbegin(), reversed_answer.crend());
}

short unsigned zero_or_one(unsigned k) {
    if ( (k >> 1) << 1 == k )
        return 0;
    return 1;
}

std::string cleverer_unsigned_to_binary(unsigned n) {
    std::string reversed_answer;
    for (int i = 0; i < 32; i ++) {
        reversed_answer += char('0' + zero_or_one(n));
        n = n >> 1;
    }

    return std::string(reversed_answer.crbegin(), reversed_answer.crend());
}

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << cleverer_unsigned_to_binary(n) << "\n";
    return 0;
}