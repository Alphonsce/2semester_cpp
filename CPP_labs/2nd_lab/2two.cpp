#include <iostream>

union float_unsigned
{
    float f;
    unsigned int u;
};

short unsigned zero_or_one(unsigned k) {
    if ( (k >> 1) << 1 == k )
        return 0;
    return 1;
}

void print_unsigned_to_binary(unsigned int n) {
    std::string reversed_answer;
    for (int i = 0; i < 32; i ++) {
        reversed_answer += char('0' + zero_or_one(n));
        n = n >> 1;
    }
    std::string answer = std::string(reversed_answer.crbegin(), reversed_answer.crend());

    std::cout << answer[0] << ' ';
    for (int i = 1; i < 9; i ++) {
        std::cout << answer[i];
    }
    std::cout << ' ';
    for (int i = 9; i < 32; i ++) {
        std::cout << answer[i];
    }
    std::cout << std::endl;
}

int main() {
    std::cout << std::fixed;
    std::cout.precision(2);
    unsigned how_many_powers;
    std::cout << "Введите количество степеней 10: " << std::endl;
    std::cin >> how_many_powers;

    float_unsigned uni_value;
    uni_value.f = 1.0;
    for (int p = 1; p < how_many_powers; p++) {
        uni_value.f *= 10.0;
        std::cout << "Степень: " << p << '\n' << "В формате float: " << std::endl; 
        std::cout << uni_value.f << std::endl;
        std::cout << "В двоичном представлении: " << std::endl; 
        print_unsigned_to_binary(uni_value.u);
        std::cout << "----------------------" << std::endl;
    }
    return 0;
}