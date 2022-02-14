#include <iostream>
#include <string>
#include <vector>
#include <map>      // аналог словаря

int main()
{
    using namespace std;    //используем все классы из пространства имен std
    int x = -5;
    double y = 5.55;
    bool logical_value = false;
    char symbol = 'Z';

    string hw = "Hello, world!";

    vector<int> nums = {1, 3, 5, 7};

    cout << nums.size();     // используем метод .size() объекта класса vectort

    return 0;
}