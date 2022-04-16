#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// int * compress(int ** matrix, int n, int m) {
//     int* arr = new int[n * 3];      // по условию в каждой строке матрицы ровно 3 ненулевых
//     unsigned* non_zero = new unsigned;
//     unsigned* pos_in_arr = new unsigned;

//     for (int i = 0; i < n; i ++) {
//         *non_zero = 0;

//         for (int j = 0; j < m; j ++) {
//             if (matrix[i][j] != 0) {
//                 arr[*pos_in_arr] = matrix[i][j];
//                 *pos_in_arr += 1;
//                 *non_zero += 1;
//             }
//         }
//         if (*non_zero != 3) {     // если в какой-то строке матрицы не 3 ненулевых, то это конец
//             delete [] arr;
//             delete [] matrix;
//             delete non_zero;
//             delete pos_in_arr;
//             return nullptr;
//         }
//     }
//     delete [] matrix;
//     delete non_zero;
//     delete pos_in_arr;
//     return arr;
// }

int* compress(int ** matrix, int n, int m)
{
    int* arr = new int[3 * n];
    unsigned *non_zero = new unsigned;

    for (int i = 0; i < n; ++i) {
        *non_zero = 0;

        for (int j = 0; j < m; ++j) {
            if (*(*(matrix + i) + j) != 0) {
                *arr = *(*(matrix + i) + j);
                arr += 1;
                *non_zero += 1;
            }
        }

        if (*non_zero != 3) {
            delete [] arr;
            delete [] matrix;
            delete non_zero;
            return nullptr;
        }
    }

    delete [] matrix;
    delete non_zero;
    return arr - 3 * n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int* compressed = compress(a, n, m);

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}