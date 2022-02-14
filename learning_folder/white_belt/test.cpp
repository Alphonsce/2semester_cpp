#include <iostream>
#include <vector>

int main()
{
    using namespace std;

    vector<int> a = {1, 2, 3};

    for (auto i: a) {
        cout << i << endl;
    }

    return 0;
}