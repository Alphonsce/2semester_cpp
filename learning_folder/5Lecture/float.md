# Float

Float состоит из знакового бита, битов под экспоненту и мантиссы

Флот - это просто некоторое число отсечек, которыми мы пытаемся покрыть нужный диапазон с постоянной относительной погрешностью

Мы можем не попасть в какую-то отсечку, тогда происходят ошибки округления,
можно отслеживать куда попало число - левее середины между отсечек/ посередине / правее середины,
если попали в середину, то округляем по правилу Кехена 


## Никогда не надо сравнивать флоты через ==
Потому что ошибки округления скапливаются при нескольких операциях, поэтому надо просто вводить tolerance, с которым надо определить значение


## Машинное эпсилон
https://youtu.be/wXG3-7zxV5k?t=3447

Какое минимальное число я могу прибавить к единице, чтобы получилась не единица
```cpp

#include <limits>
int main {

    std::cout << numeric_limits<long double>::epsilon() << std:: endl;

}
```

long double: 1.0842e-19 точность 


### Для вычислений нужно нормировать, чтобы вычисления были в районе единицы - хуже всего в районе нуля

## Кумулятивная ошибка
https://youtu.be/wXG3-7zxV5k?t=3931 