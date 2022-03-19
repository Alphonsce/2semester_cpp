### Расширение массива:
```cpp
// Мы переаем указатель на указатель, то есть мы хотим передаем указатель на ту ячейку памяти, в которой хранится
// указатель на 0 элемент массива
void expaind(int** pt_arr, int old_size, int new_size) {
    int* new_arr = new int[new_size];
    for (int i = 0; i < old_size; i++) {
        new_arr[i] = (*pt_arr)[i];
    }
    delete[] *pt_arr;
    *pt_arr = new_arr;
}


int main() {

    int* arr = new int[100];
    expand(&arr, 100, 10000);
    return 0;
}
```
### Двумерные массивы.

Двумерный массив можно задать как одномерный и просто i * m + j индексировать, а можно нормально сделать:

```cpp

int** mat = new int*[rows]  // массив указателей на 0 элементы
for (int i = 0; i < columns; i ++) {
    mat[i] = new int[columns];
}

for (int i = 0; i < rows; i++) {
    delete[] mat[i]
}
delete[] m;

```

### Для чего нужен struct:

В struct не принято писать методы, он обычно используется для хранения данных, например можно сделать структуру, которая хранит число и указатель на следующее число в массиве, а потом таким образом сделать массив из таких структур и хранить такие данные.