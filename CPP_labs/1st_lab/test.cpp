#include <iostream>
#include <algorithm>

void print_matrix(int n, int **arr)
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
    int arr[n][n], arr1[5] = {5, 6, 1, 2, 4};
    std::sort(arr1, arr1 + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << endl;
    }
}
