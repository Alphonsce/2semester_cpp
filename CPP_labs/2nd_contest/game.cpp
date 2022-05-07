#include <iostream>
#include <cmath>

int get_min_E(int* CoordsY, int n) {
    int* MinE = new int[n]; //Массив с минимальными энергозатратами от начала до платформы

    MinE[0] = 0; //От начала до начала энергия не потратится
    MinE[1] = abs(CoordsY[1] - CoordsY[0]); //Здесь тоже однозначно
 
    int E1, E2; //Затраты энергиив при разных случаях
    for (int i = 2; i < n; i ++) {
        E1 = abs(CoordsY[i] - CoordsY[i - 1]); //Энергия при обычном прыжке
        E2 = 3 * abs(CoordsY[i] - CoordsY[i - 2]); //Энергия при СУПЕР-прыжке
 
        //Найдем минимальную энергию, которую может затратить игрок
        if (E1 + MinE[i - 1] < E2 + MinE[i - 2]) // Если выгоднее прыгнуть с ближайшей, то
            MinE[i] = E1 + MinE[i - 1]; //прыгаем с ближайшей
        else // а если выгоднее прыгуть с дальней
            MinE[i] = E2 + MinE[i - 2]; //то прыгаем с дальней
    }
    int total_min_energy = MinE[n - 1];

    delete[] MinE;
    return total_min_energy;
}

int main() {
    int n;
    std::cin >> n;
    int* CoordsY = new int[n];
 
    //Ввод
    for (int i = 0; i < n; i ++)
        std::cin >> CoordsY[i];

    std::cout << get_min_E(CoordsY, n) << std::endl;

    delete[] CoordsY;
    return 0;
}