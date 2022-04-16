#include <iostream>
using std::cout;
using std::endl;

const unsigned int N = 5;
const int left[N]  = {5, 4, 3, 2, 1}; // command code 1
const int right[N] = {1, 2, 3, 4, 5}; // command code 2
const int back[N]  = {1, 1, 1, 1, 1}; // command code 3
const int meow[N]  = {3, 2, 3, 2, 5}; // command code 4

bool compare_array_and_command(int a[N], const int b[N]) {
    // cout << *a << " " << *(a + 1) << " " << *(a + 2) << " " << *(a + 3) << " " << *(a + 4) << " " << endl;
    // cout << *b << " " << *(b + 1) << " " << *(b + 2) << " " << *(b + 3) << " " << *(b + 4) << " " << endl;
    // cout << endl;
    for (unsigned int i = 0; i < N; i++) {
        if (!(*(a + i) == *(b + i)))
            return false;
    }
    return true;
}

void recognize(int* data_start, int* data_end, int* command, int** frame) {
    int* current = data_start;
    int found_command = 0;
    for (;current < data_end - N + 1; current++) {
        if (compare_array_and_command(current, left)) {
            found_command = 1;
            break;
        }
        else if (compare_array_and_command(current, right)) {
            found_command = 2;
            break;
        }
        else if (compare_array_and_command(current, back)) {
            found_command = 3;
            break;
        }
        else if (compare_array_and_command(current, meow)) {
            found_command = 4;
            break;
        }
    }
    *command = found_command;
    *frame = current;
    return;
}

int main()
{
    const int L = 21;
    int mindstream[L] = {3, 2, 3, 2, 5, 2, 3, 8, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5};
    int command = -1;
    int* frame = mindstream;
    int* end = mindstream + L;
    while (command)
    {
        recognize(frame, end, &command, &frame);
        if (!command) break;
        switch(command)
        {
            case 1:
                cout << "left ";
                break;
            case 2:
                cout << "right ";
                break;
            case 3:
                cout << "back ";
                break;
            case 4:
                cout << "MEOOOOW ";
                break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}