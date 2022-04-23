#include <iostream>
#include <vector>

// шашка стоит на i, j позиции, найти сколько способов попасть в дамки - то есть сколько способов попасть на последний ряд

void print_array(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << ' ';
    std::cout << std::endl; 
}

void print_matrix(std::vector<std::vector<int>> mat) {
    for (int i = 0; i < mat.size(); i ++) {
        print_array(mat[i]);
    }
}

int get_ways(int i_s, int j_s) {
    std::vector<std::vector<int>> ways;
    std::vector<int> v (8, 0);
    for (int i = 0; i < 8; i++) {
        ways.push_back(v);
    }

    // базу рекурсии некоторую задаем:
    ways[i_s][j_s] = 0;
    if (j_s != 0)
        ways[i_s + 1][j_s + 1] = 1;
    ways[i_s + 1][j_s - 1] = 1;
    
    for (int i = i_s + 2; i < 8; i ++) {  // шашки не умеют ходить назад
        for (int j = 0; j < 8; j ++) {
            if (j != 0)
                ways[i][j] += ways[i - 1][j_s - 1];
            ways[i][j] += ways[i - 1][j + 1];
        }
    }

    int ways_for_goal = 0;
    for (int j = 0; j < 8; j ++) {
        ways_for_goal += ways[7][j];
    }

    print_matrix(ways);

    return ways_for_goal;
}

int main() {
    int i, j;
    std::cin >> i >> j;

    std::cout << get_ways(i, j) << std::endl;

    return 0;
}