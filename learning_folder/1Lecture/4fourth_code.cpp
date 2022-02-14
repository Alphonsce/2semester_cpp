#include <iostream>

int main()
{
    using namespace std;
    int start, stop, step, x, N;


    start = 1, stop = 5, step = 1;      // , - это оператор "и"
// можно сгенерировать геометрическую прогрессию написав просто x *= step
    for (x = start; x < stop; x += step){
        cout << x << endl;
    }
// break и continue тоже существуют
// && - это и, || - это или, ! - это не

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x;
    }

    return 0;

}

int max(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}