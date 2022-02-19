#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

int gen_random(int number)
{
    return rand() % number;
}

void print_matrix(int n, char** arr)
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
    for (auto v: vec)
    {
        print_vector(v);
    }
}

bool find_vector_in_2D_vector(const std::vector<int>& v, const std::vector<std::vector<int>>& vec)
{
    for (auto u: vec)
    {
        if (u == v)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    using namespace std;
    int size, cryst_amount, steps = 0, seed = 105;
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

    char** grid = new char*[size];
    for (int i = 0; i < size; i++)
        grid[i] = new char[size];

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
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = '0';
        }
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
    vector<vector<int> > all_stops;

    while (all_stops.size() < actual_amount)
    {
        // defining positions, which we don't need to move
        all_stops.clear();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {

                if ( (i == 0) || (i == size - 1) || (j == 0) || (j == size - 1) )
                {
                    if (grid[i][j] == '*')
                    {
                        all_stops.push_back({i, j});
                    }
                }
                // else if ( (j == 0) || (j == size - 1) )
                // {
                //     if (grid[i][j] == '*')
                //     {
                //         all_stops.push_back({i, j});
                //     }
                // }
                else if ( (grid[i + 1][j] == '*') || (grid[i - 1][j] == '*') || (grid[i][j + 1] == '*') || (grid[i][j - 1] == '*') )
                {
                    if (grid[i][j] == '*')
                    {
                        all_stops.push_back({i, j});
                    }
                }
            }
        }    

        // move all the crystalls at the same time
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                vector<int> cur_pos = {i, j};
                if (find_vector_in_2D_vector(cur_pos, all_stops))
                {
                    continue;
                }
                else if (grid[i][j] == '*' && (i != 0) && (i != size - 1) && (j != 0) && (j != size - 1) )
                {
                    int r = gen_random(4);
                    if (r == 0)
                    {
                        grid[i][j] = '0';
                        grid[i + 1][j] = '*';
                    }
                    else if (r == 1)
                    {
                        grid[i][j] = '0';
                        grid[i - 1][j] = '*';
                    }
                    else if (r == 2)
                    {
                        grid[i][j] = '0';
                        grid[i][j + 1] = '*';
                    }
                    else
                    {
                        grid[i][j] = '0';
                        grid[i][j - 1] = '*';
                    }
                }
            }
        }
        steps += 1;
        // if (steps == 500){break;}
        //----------print------------
        //print_matrix(size, grid);
        // print_2D_vector(all_stops);
        //cout << all_stops.size() << ' ' << cryst_amount << endl;
        // break;
        // cout << "---------------------" << endl;
    }    

    cout << "------------------" << endl << "Grid at the end: " << endl;

    print_matrix(size, grid);

    cout << "Number of steps to end the process: " << steps << endl;
    return 0;
}