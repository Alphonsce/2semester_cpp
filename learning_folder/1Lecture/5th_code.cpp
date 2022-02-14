#include <iostream>
#include <string>

//Внутри 1 функции мы 2 не можем вызвать, так как про нее еще ничего не известно, но методы класса мы в любом порадке можем писать

int func1(int a)
{
    int smth;
    return smth;
}

void func2(int b)
{
    std::string smth = "You inserted number: ";
    std::cout << smth + std::to_string(b) << std::endl;
}

int main()
{
    using namespace std;
    func2(55);
    return 0;

}
