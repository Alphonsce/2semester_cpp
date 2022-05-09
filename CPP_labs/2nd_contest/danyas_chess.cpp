#include <iostream>
#include <string>
#include <vector>

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

int get_possibilities(
    std::vector<std::vector<bool> > field,
    std::vector<std::vector<int> > ways,
    std::string pos
    ) {
    // проходимся по всем позициям и для каждой позиции смотрим количество способов попасть в ферзи
    for (int i = 7; i >= 0; i --){
		for (int j = 0; j < 8; j ++){
			
			if (i == 7) {
                ways[i][j] = 1;
            }
            else {
				if (!field[i + 1][j]) // если следующая не черная
					ways[i][j] += ways[i + 1][j];

				if (j != 0) // вложенное услвие чтобы не было seg fault и мы не обратились к -1 ячейке памяти
				{
					if (field[i + 1][j - 1])
						ways[i][j] += ways[i + 1][j - 1];
				}
				if (j != 7)
				{
					if (field[i + 1][j + 1])
						ways[i][j] += ways[i + 1][j + 1];
				}
			}
		}
	}
    // print_2d_array(ways);
    return ways[pos[1] - 49][pos[0] - 97];
}

int main(){
	int n;
    std::string pos;
	std::cin >> n;

    std::vector<std::vector<bool> > field;
    std::vector<bool> v (8, 0);
    for (int i = 0; i < 8; i++) {
        field.push_back(v);
    }

    // Заполняем булевское поле координатами черных пешек:

	for (int i = 0; i < n; i++){
		std::cin >> pos;
		field[pos[1] - 49][pos[0] - 97] = true;
	}

    // Создаем массив для мемоизации количества способов попасть из i, j позиции в ферзи
    // при данном расположении черных пешек:

    std::vector<std::vector<int> > ways;
    std::vector<int> u (8, 0);
    for (int i = 0; i < 8; i++) {
        ways.push_back(u);
    }

	std::cin >> pos;

    std::cout << get_possibilities(field, ways, pos) << std::endl;

	return 0;
}