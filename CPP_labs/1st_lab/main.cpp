#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

int gen_random(int &seed, int number)
{
    using namespace std;
    seed++;
    srand(seed);
    return rand() % number;
}

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
    int size, cryst_amount, steps, seed = 112;
    // cryst_amount is a total number of crystalls

    seed = gen_random(seed, seed);
    cout << "Insert size of the grid: ";
    cin >> size;
    cout << endl;
    cout << "Insert amount of crystalls: ";
    cin >> cryst_amount;
    cout << endl;

    int** grid = new int*[size];
    for (int i = 0; i < size; i++)
        grid[i] = new int[size];

    int init_cryst_i[cryst_amount];
    int init_cryst_j[cryst_amount];

    // initializing crystalls
    for (int i = 0; i < cryst_amount; i++)
    {
        init_cryst_i[i] = gen_random(seed, size);
        init_cryst_j[i] = gen_random(seed, size);
    }

    for (int i = 0; i < cryst_amount; i++)
    {
        cout << init_cryst_i[i] << " " << init_cryst_j[i] << endl;
    }

    //filling up the grid with crystalls:
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
    for (int i = 0; i < cryst_amount; i++)
    {
        grid[init_cryst_i[i]][init_cryst_j[i]] = 1;
    }

    //---------print-----------
    
    print_matrix(size, grid);

    return 0;
}