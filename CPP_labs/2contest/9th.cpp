#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string line;
    int boss = 0, total = 0, speed; 

    while (boss != 1)
    {
        cin >> speed >> line;
        if (line == "A999AA")
        {
            boss = 1;
        }

        if ((speed > 60) and (boss == 0))
        {
            if (line[1] == line[2] and line[2] == line[3])
            {
                total += 1000;
            }
            else if (line[1] == line[2] || line[2] == line[3] || line[1] == line[3])
            {
                total += 500;
            }
            else
            {
                total += 100;
            }
        }

    }
    cout << total << endl;

    return 0;
}