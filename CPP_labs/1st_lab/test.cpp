#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>


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

int main()
{
    using namespace std;
    // vector<int> u(2, 0);
    // vector<vector<int> > v(5, u);
    
    vector<vector<int> > v;
    vector<int> u = {2, 3, 1};
    v.push_back({1, 2, 3});
    v.push_back(u);
    print_2D_vector(v);
    v.clear();
    cout << v.size() << endl;
}
