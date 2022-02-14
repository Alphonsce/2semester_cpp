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
    int n, numbers[10000], k = 0, maxx = 0, maxes = 0;

    cin >> n;
    while (n != 0)
    {
        numbers[k] = n;
        k += 1;
        maxx = max(maxx, n);
        cin >> n;
    }
    for (int i = 0; i < k; i++)
    {
        if (numbers[i] == maxx)
        {
            maxes += 1;
        }
        
    }
    cout << maxes << endl;
    return 0;
}