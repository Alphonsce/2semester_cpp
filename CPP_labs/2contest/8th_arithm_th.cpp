#include <iostream>

int main()
{
    using namespace std;
    int numb, delimeters = 0;

    cin >> numb;
    for (int i = 2; i <= numb; i++)
    {
        if (numb % i == 0)
        {
            cout << i << endl;
            numb = numb / i;
            i -= 1;
        }
    }

    return 0;
}