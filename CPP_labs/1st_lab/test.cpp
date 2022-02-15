#include <iostream>
#include <algorithm>
#include <cstdlib>


void print_matrix(int n, int** arr)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    using namespace std;
    int n;
    cin >> n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][i] = i + j;

    print_matrix(n, arr);
}
