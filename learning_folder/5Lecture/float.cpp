#include <iostream>
#include <limits>

int main()
{   
    using namespace std;
    long double a = 3.1415;

    cout << numeric_limits<long double>::epsilon() << endl;
    
    return 0;
}