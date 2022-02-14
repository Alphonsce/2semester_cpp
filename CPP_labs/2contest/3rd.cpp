#include <iostream>

int main()
{
    using namespace std;
    int k_evens = 0, numb;

    cin >> numb;
    while (numb != 0)
    {
        if (numb % 2 == 0)
        {
            k_evens += 1;
        }
        cin >> numb;
    }
    cout << k_evens << endl;

    return 0;
}