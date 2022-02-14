#include <iostream>

int main()
{
    using namespace std;
    const int n = 5;
    int a[n], sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << "sum = " << sum << endl;
    return 0;
}