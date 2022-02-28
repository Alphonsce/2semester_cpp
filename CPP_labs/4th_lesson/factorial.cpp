#include <iostream>

unsigned factorial(unsigned n)
{

    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);

}

int TailFactorial(int n, int a)
{
    if (n == 1)
        return a;
    return TailFactorial(n - 1, n * a);
}

int main()
{
    std::cout << factorial(5) << std::endl;
    return 0;
}