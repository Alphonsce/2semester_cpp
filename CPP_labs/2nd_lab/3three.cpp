#include <string>
#include <iostream>

int main() {
    float val = 1.0;
    float final;
    int i = 0;
    std::cout << "Введите шаг окончания:: " << std::endl;
    std::cin >> final;
    while (val != final) {
        val += 1.0;
        if (i % 100 == 0) 
            std::cout << val << std::endl;
        i += 1;
    }
    return 0;
}