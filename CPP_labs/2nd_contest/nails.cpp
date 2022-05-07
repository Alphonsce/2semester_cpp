#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
 
int get_number_of_nails(std::string input) {
    int numb = 1;
    // std::cout << input << std::endl;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
        if (isspace(input[i])) {
            numb += 1;
        }
    }
    return numb;
}

void print_array(std::vector<int> arr) {
    int n = arr.size();
    for (int i = 0 ;i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void print_array(std::string* arr) {
    int n = 100;
    for (int i = 0 ;i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void print_total_length(std::vector<int> coords, int n) {
    std::sort(coords.begin(), coords.end());
    print_array(coords);
    std::vector<int> s;
    if (n == 2) {
       std::cout << coords[1] - coords[0];
       return;
    }

    s.push_back(coords[1] - coords[0]); // первый всегда просто со вторым соединяем
    s.push_back(coords[2] - coords[0]);
    for (int i = 2; i < coords.size() - 1; ++ i)
        s.push_back(std::min(s[i - 1], s[i - 2]) + abs(coords[i] - coords[i + 1]));

    print_array(s);

    std::cout << s[s.size() - 1] << std::endl;
    return;
}
 
int main() {
    int coord, n;
    std::vector<int> coords;
    std::string input;
    std::getline(std::cin, input);  // ввод строки иначе с пробелами не происходит в одну переменную

    n = get_number_of_nails(input); // нужно считать число гвоздей иначе потом не получиться поток направить просто
    // по какой-то причине такой подсчет ломал их компиллятор

    int i = 0, count = 0;
    std::string oneWord;
    std::stringstream ssin0(input);  // используется для перевода строки в поток, чтобы сразу заполнить вектор
    while(ssin0 >> oneWord) { ++count;}
    n = count;

    std::stringstream ssin(input);  // тот поток уже считали для подсчета числа элементов, создаем новый

    while (ssin.good() && i < n){
        ssin >> coord;
        ++i;
        coords.push_back(coord);
    }   

    print_total_length(coords, n);
    return 0;
}