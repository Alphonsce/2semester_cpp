#include <iostream>
#include <string>
#include <cmath>

int smaller_pow_of60(int numb)
{
    int k = 0;
    while (pow(60, k) < numb)
    {
        if (pow(60, k + 1) > numb)
        {
            break;
        }
        k++;
    }
    return k;
}

std::string number_to_vav(int numb)
{
    using namespace std;
    if (numb == 0)
    {
        return "";
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
    int numb, numb1, k;

    cin >> numb;
    numb1 = numb;
    k = smaller_pow_of60(numb);
    int arr[k + 1];

    for (int i = k; i >= 0; i--)
    {
        //arr - массив множителей перед степенями 60
        int a = pow(60, i);
        arr[i] = numb / a;
        //cout << a << endl;
        numb -= a * (numb / a);
    }

    string line = "";
    for (int i = k; i >= 0; i--)
    {   
        string appended;
        if (i != 0)
        {
            appended = number_to_vav(arr[i]).append(".");
        }
        else 
        {
            appended = number_to_vav(arr[i]);
        }
        line.append(appended);
    }

    cout << line << endl;

    return 0;

}