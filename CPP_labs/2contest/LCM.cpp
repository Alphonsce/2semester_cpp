#include <iostream>

int gcd(int a, int b)
{ // Алгоритм Евклида

    while (a != b) {     
        if (a > b) {
            a -= b;

        } else {
            b -= a;
        }
    }
    return a;
}

int calc_LCM(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    using namespace std;
    int x, y;

    cin >> x >> y;
    cout << calc_LCM(x, y) << endl;
    return 0;
}