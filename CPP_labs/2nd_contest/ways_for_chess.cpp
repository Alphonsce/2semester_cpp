#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

void print_array(std::vector<int> arr) {
    for (int i = 0 ;i < arr.size(); i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void print_2d_array(std::vector<std::vector<int> > mat) {
    for (int i = 0; i < mat.size(); ++ i) {
        std::cout << i << ") ";
        print_array(mat[i]);
    }
    return;
}

bool check_in(std::vector<int> arr, int a) {
    for (int i = 0; i < arr.size(); ++ i) {
        if (a == arr[i]) return true;
    }
    return false;
}

int get_total_ways(
    std::vector<int> is,
    std::vector<int> js,
    int w_i, int w_j
    ) {

    if (w_i == 7) {
        return 1;
    }
    std::vector<std::vector<int>> ways;
    std::vector<int> v (8, 0);
    for (int i = 0; i < 8; i++) {
        ways.push_back(v);
    }

    ways[w_i][w_j] = 1;

    for (int i = w_i + 1; i < 8; i ++) {  // пешки не умеют ходить назад
        for (int j = 0; j < 8; j ++) {

            // if ( (check_in(is, i + 1) && check_in(js, j)) ) {
            //     std::cout << i << ' ' << j << std::endl;
            //     continue;
            // } else {
            //     ways[i][j] += ways[i - 1][j];
            // }

            if ( (check_in(is, i) && check_in(js, j)) ) {
                std::cout << i << ' ' << j << std::endl;
                // ways[i][j] -= 1;
            } else {
                ways[i][j] += ways[i - 1][j];
            }

            if (j != 0) {
                if (check_in(is, i) && check_in(js, j - 1)) {
                    ways[i][j - 1] += ways[i - 1][j];
                }
            }

            if (j != 7) {
                if (check_in(is, i) && check_in(js, j + 1)) {
                    ways[i][j + 1] += ways[i - 1][j];
                }
            }
        }
    }

    print_2d_array(ways);

    int ways_for_goal = 0;
    for (int j = 0; j < 8; j ++) {
        ways_for_goal += ways[7][j];
    }

    return ways_for_goal;

}

int main() {
    std::map<char, int> LetterToNumber;
    const char letters[8] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    const int numbers[8] {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < 8; ++ i) {
        LetterToNumber[letters[i]] = numbers[i];
    }

    int n, w_i, w_j;
    std::string line;
    std::cin >> n;

    std::vector<int> is, js; // координаты черных пешек

    for (int i = 0; i < n; ++ i) {
        std::cin >> line;
        js.push_back(LetterToNumber[line[0]] - 1);  // -1 чтобы индексы не вылетали у ways в функции
        is.push_back(line[1] - '0' - 1);
    }

    // Вводим белую:
    std::cin >> line;
    w_j = LetterToNumber[line[0]] - 1;
    w_i = line[1] - '0' - 1;

    // print_array(is);
    // print_array(js);

    std::cout << get_total_ways(is, js, w_i, w_j) << std::endl;

    return 0;

}