#include <iostream>

void swap_us(int &x, int &y)
{
    // Функция меняет не локальные переменные, она меняет значения лежащие в указанных ячейках памяти
    // То есть мы так можем изменять значения даже локальных перменных внутри функций

    // Внутри этой функции ни на что память не выделяется, кроме tmp
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    using namespace std;
    int a, b;

    a = 5, b = 11;
    swap_us(a, b);
    cout << a << ' ' << b << endl;

    return 0;
}