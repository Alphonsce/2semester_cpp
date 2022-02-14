#include <iostream>

int main()
{
    using namespace std;
    float numb, iterations = 0, twos = 1;

    cin >> numb;
    int numb1 = numb;
    while (numb > 1)
    {
        numb = numb / 2;
        iterations += 1;
    }

    for (int i = 0; i < iterations; i++){
        twos *= 2;
    }

    if (numb1 == twos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}