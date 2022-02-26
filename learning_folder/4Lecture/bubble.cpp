#include <iostream>


void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// Передаем в качестве переменной тип инт* - указатель на первый элемент массива
void BubbleSort(int n, int* arr)
{   bool swapped;
    for (int i = 0; i < n; i++)
    {   swapped = false;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int arr[]= {3, 2, 1, 235, 4353, 13451, 1451, 3451, 14351, 145, -5, 1235, 123412, 123412, 1234, 134124,346, 6756, 67, 675, 67, 78657, 85, 7867, 85678, 5678, 5678, 5678, 5678, 5678, 56, 7856, 78567, 8};
    BubbleSort(sizeof(arr) / sizeof(arr[0]), arr);

    return 0;
}
