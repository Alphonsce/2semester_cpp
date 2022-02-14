#include <iostream>
#include <string> 

int main()
{
    using namespace std;

    string name;
    int age;

    cout << "Whats ur name? And how old r u?" << endl;
    cin >> name >> age;

    cout << "So, your name is " << name << " and you are " << age << " years old\n";

    return 0;
}

// Мы компилируем код сначала, а потом, чтобы запустить его мы вызываем a.out

// Можно перенаправлять потоки ввода и вывода:
// Чтобы скормить ввод из файла, делаем: ./a.out < in.txt
// Чтобы сделать вывод в файл, делаем: ./a.out > out.txt
// Можно сразу оба: ./a.out > out.txt <in.txt

// Существует три потока: ввода, вывода, ошибок, поток ошибок всегда попадает на консоль