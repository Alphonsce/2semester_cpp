#include <iostream>

// Обход локальности переменной, если надо ее изменить - это ссылка:
// Мы просто изменяем значение в памяти

void increment_me(unsigned &x)
{
    //производится действие над памятью, выделенной для переденной переменной
    ++ x;
}

int main()
{
    unsigned a = 5;
    increment_me(a);
    std::cout << a << std::endl;
    // 6
    return 0;
}