#include <iostream>     // библиотека, подключающая поток ввода/вывода
#include <string>
#include <vector>

//using namespace std;

int main ()     // main function, int stands here for return type, because we return 0 at the end of the main function
{
//std - пространство имен, допустим у нас есть две одинаково названные функции cout, но мы используем именно cout из пространства имен std
// namespaces prevents name conflicts
//we can use using namespace std, which means we will import everything from std
// cout is an object of a class here, он типо экземпляр класса ostream
// << - это оператор, cout и "Hello World!\n" - операнды
    std::cout << "Hello World!\n";
    return 0;
}

// ./a.out