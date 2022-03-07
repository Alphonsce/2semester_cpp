#include <iostream>
#include <vector>
#include <algorithm>

void print_array(float *arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << std::endl;
}

void move_array_one_forward_starting_from_pivot(float *arr, int size, int pivot)
{
    for (int i = size - 1; i > pivot; i--)
    {
        arr[i] = arr[i - 1];
    }
}

int main()
{
    int n, m;
    float a; 
    std::cout << "Введите длину потока ввода" << std::endl;
    std::cin >> n;
    std::cout << "Введите количество максимумов, которое необходимо вывести" << std::endl;
    std::cin >> m;

    float max[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> a;
        max[i] = a;
    }
    
    std::sort(max, max + m, std::greater<float>());
// массив сортируется к виду 5 4 3 2 1
// 3 2 1 ---> a 3 2
    for (int i = 0 ;i < n - m; i++)
    {
        std::cin >> a;    
        for (int j = 0; j < m; j++)
        {
            if (a >= max[j])
            {
                move_array_one_forward_starting_from_pivot(max, m, j);
                max[j] = a;
                break;  
            }
        }
    }

    print_array(max, m);
    return 0;
}
