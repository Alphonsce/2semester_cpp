#include <iostream>
#include <vector>
#include <algorithm>

void print_vec(std::vector<int> v) {
    for (int i = 0; i < v.size(); i ++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

// I will need sorted occupied positions:
void my_sort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

int get_boris_place(std::vector<int> occupied, int boris_len) {
    int boris_pos = -1;
    // дырка - разность координат минус 1
    // print_vec(occupied);
    if (occupied[0] >= boris_len)
        return 0;

    for (int i = 0; i < occupied.size() - 1; i ++) {
        if (occupied[i] - occupied[i + 1] - 1 >= boris_len) {
            boris_pos = occupied[i] + 1;
            return boris_pos;
        }
    }

    if (occupied[occupied.size() - 1] < 29 - boris_len) {
        return occupied[occupied.size() - 1] + 1;
    }

    return boris_pos;
}

int main() {
    std::vector<int> occupied;
    int n, pos, len, boris_len;

    std::cin >> n;

    for (int i = 0; i < n; i ++) {
        std::cin >> pos >> len;
        for (int j = 0; j < len; j++) {
            occupied.push_back(pos + j);
        }
    }

    my_sort(occupied);

    std::cin >> boris_len;

    if (n != 0)
        std::cout << get_boris_place(occupied, boris_len) << std::endl;
    else
        std::cout << 0 << std::endl;

    return 0;
}