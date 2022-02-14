#include <iostream>

std::string number_to_vav(int numb)
{
    using namespace std;
    if (numb == 0)
    {
        return ".";
    }
    int int_tens = numb / 10;
    int int_ones = numb % 10;
    string tens_line(int_tens, '<');
    string ones_line(int_ones, 'v');
    tens_line.append(ones_line);
    return tens_line;
}

int main()
{
    using namespace std;

    cout << number_to_vav(21) << endl;
    

    return 0;
}