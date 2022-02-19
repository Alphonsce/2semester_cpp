#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

int gen_random(int number)
{
    return rand() % number;
}

void print_matrix(int n, std::vector<std::vector<char> > arr)
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

void print_vector(const std::vector<int>& vec)
{
    for (int s: vec)
    {
        std::cout << s << ' ';
    }
    std::cout << '\n';
}

void print_2D_vector(const std::vector<std::vector<int>>& vec)
{
    for (std::vector<int> v: vec)
    {
        print_vector(v);
    }
}

bool find_vector_in_2D_vector(const std::vector<int>& v, const std::vector<std::vector<int>>& vec)
{
    for (std::vector<int> u: vec)
    {
        if (u == v)
        {
            return true;
        }
    }
    return false;
}

bool is_already_stopped(int size, std::vector<std::vector<char> > grid, int i, int j) {
    if (grid[i][j] == '*')
    {
        if ( (i == 0) || (i == size - 1) || (j == 0) || (j == size - 1) )
        {
            return true;
        }
        else if ( (grid[i + 1][j] == '*') || (grid[i - 1][j] == '*') || (grid[i][j + 1] == '*') || (grid[i][j - 1] == '*') )
        {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int>> calculate_all_stops(int size, std::vector<std::vector<char> > grid) {
    std::vector<std::vector<int>> all_stops;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (is_already_stopped(size, grid, i, j)) {
                all_stops.push_back({i, j});
            }
        }
    }
    return all_stops;
}

int main()
{
    using namespace std;
    int size;
    int cryst_amount;
    int steps = 0;
    int seed = 105;     //105 was initial one
    bool one_marker = false;
    // cryst_amount is a total number of crystalls

    srand(seed);
    cout << "Insert size of the grid: ";
    cin >> size;
    cout << endl;
    cout << "Insert amount of crystalls: ";
    cin >> cryst_amount;
    cout << endl;
    if (cryst_amount == 1)
    {
        one_marker = true;
    }

    vector<vector<char> > grid;

    int init_cryst_i[cryst_amount];
    int init_cryst_j[cryst_amount];

    // initializing crystalls
    for (int i = 0; i < cryst_amount; i++)
    {
        init_cryst_i[i] = gen_random(size);
        init_cryst_j[i] = gen_random(size);
    }

    // filling up the grid with crystalls:
    for (int i = 0; i < size; i++)
    {
        vector<char> gridVector;
        for (int j = 0; j < size; j++)
        {
            gridVector.push_back('0');
        }
        grid.push_back(gridVector);
    }
    for (int i = 0; i < cryst_amount; i++)
    {
        grid[init_cryst_i[i]][init_cryst_j[i]] = '*';
    }
    // counting amount of crystalls without repetitions:
    int actual_amount = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == '*')
            {
                actual_amount++;
            }
        }
    }
    cryst_amount = actual_amount;
    if (one_marker)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                grid[i][j] = '0';
            }
        }
        grid[(size - 1) / 2][(size - 1) / 2] = '*';
        actual_amount = 1;
    }

    cout << "Grid at the beggining: " << endl;
    print_matrix(size, grid);
    cout << "------------------" << endl;

    // starting the movement of the crystalls here
    vector<vector<int>> all_stops = calculate_all_stops(size, grid);
    while (all_stops.size() < actual_amount)
    {
        // defining positions, which we don't need to move
        // move all the crystalls at the same time
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                vector<int> cur_pos = {i, j};
                if (grid[i][j] == '0' || find_vector_in_2D_vector(cur_pos, all_stops))
                    continue;
                else
                {
                    grid[i][j] = '0';
                    int r = gen_random(4);
                    int new_i, new_j;
                    if (r == 0)
                    {
                        new_i = i + 1;
                        new_j = j;
                    }
                    else if (r == 1)
                    {
                        new_i = i - 1;
                        new_j = j;
                    }
                    else if (r == 2)
                    {
                        new_i = i;
                        new_j = j + 1;
                        j += 1;
                    }
                    else
                    {
                        new_i = i;
                        new_j = j - 1;
                    }
                    grid[new_i][new_j] = '*';

                    if (is_already_stopped(size, grid, new_i, new_j)) {
                        all_stops.push_back({new_i, new_j});
                        if ((j != size - 1) && grid[new_i][new_i + 1] == '*')
                            all_stops.push_back({new_i, new_j + 1});
                    }
                }
            }
        }
        steps += 1;
    }

    cout << "------------------" << endl << "Grid at the end: " << endl;

    print_matrix(size, grid);

    cout << "Number of steps to end the process: " <<  steps  << endl;
    return 0;
}