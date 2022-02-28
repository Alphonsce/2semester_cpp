#include <iostream>

double Power(double x, int pow)
{   
    int x0 = x;
    for (int i = 0; i < pow - 1; i++)
        x *= x0;
    return x;
}

float RootDichotomy(float x, float a, float b, float epsilon)
{
    double center = (b + a) / 2.0;
    if ((b - a) < epsilon)
        return center;

    if (center * center > x)
        return RootDichotomy(x, a, center, epsilon);

    return RootDichotomy(x, center, b, epsilon);
}

double FindPowerDichotomy(double x, double a, double b, double epsilon, int power)
{
    // x: число для которого вычисляем степень
    // a: левая граница отрезка
    // b: правая граница отрезка
    // epsilon: необходимая точность
    // power: степень корня
    double center = (b + a) / 2.0;
    if ((b - a) < epsilon)
        return center;

    if (Power(center, power) > x)
        return FindPowerDichotomy(x, a, center, epsilon, power);

    return FindPowerDichotomy(x, center, b, epsilon, power);
}

int main()
{   
    std::cout << FindPowerDichotomy(81, 0.0, 1000.0, 0.0001, 2) << std::endl;
    return 0;
}