#include <iostream>

//int* arr is the same as arr[]
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

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
    print_array(arr, n);
}

int main()
{   
    int size = 5;
    int* arr = new int[5]{3, 2, 1};
    print_array(arr, size);
    BubbleSort(size, arr);

    return 0;
}
