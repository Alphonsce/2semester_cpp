#include <iostream>

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    using namespace std;
    int numb, maxx = 0;

    cin >> numb;
    while (numb != 0)
    {   
        if (numb % 2 == 0)
        {
            maxx = max(numb, maxx);
        }
        cin >> numb;
    }

    cout << maxx << endl;

    return 0;
}