#include <iostream>
#include <cmath>


int find_c(float a, float b)
{
    return sqrt(a * a + b * b);
}

int main()
{
    using namespace std;
    int a, b;

    cin >> a >> b;
    cout << find_c(a, b) << endl;

    return 0;
}