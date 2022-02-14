#include <iostream>

int main()
{
    using namespace std;
    int numb, delimeters = 0;

    cin >> numb;
    for (int i = 2; i * i <= numb; i++)
    {
        if (numb % i == 0)
        {
            delimeters += 1;
        }
    }

    if (delimeters == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}