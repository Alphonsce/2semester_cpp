#include <iostream>

int euclid_gcd(int a, int b)
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

int main(){
    using namespace std;
    int a, b;

    cin >> a >> b;

    cout << euclid_gcd(a, b) << endl;

    return 0;

}