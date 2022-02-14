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
    std::cout << "Never reaches this point";
}

int main(){
    using namespace std;
    int a, b;

    cout << "Insert numbers: \n";
    cin >> a >> b;

    cout << "GCD of inserted numbers: " << euclid_gcd(a, b) << endl;

    return 0;

}