Тип - синтаксическая метка, которая ограничивает поведение определенного элемента

Система типов - синтаксический метод доказательства отсутствия в программе каких-либо видов поведения

Поскольку алгоритмически нельзя доказать правильность работы программы, то можно ввести систему типов, которая будет позволять нам доказывать, что какое-либо поведение есть неверное.

- В ОО языках все делится на данные и функции, таким образом, можно ввести типы данных и типы операций.

- Тип можно рассматривать как некоторое множество, а функции просто как функции над этим множеством

## Переименования

https://youtu.be/ZwbcSsul_vA?t=1267б - просто вводим другое имя для существующего типа

```cpp
using velocity_t = int;
using dist_t = int;

int main() {
    velocity_t v = 3;
    dist_t t = 10;
    // не будет ошибки, если: (то есть здесь нет никаких проверок-небезопасно юзать переименования)
    std::cout << t + v << '\n';
    // 13
    return 0;
}
```

зачем нужно:
1) самодокументируемый код

2) тип std::size_t - максимально допустимый размер для операционной системы типа целых положительных чисел

```cpp
#include <cstdint>

fast_int8_t a; 
least_int8_t b;

```

(для псевдонима можно сделать псевдоним офк)

- С псевдонимами надо быть осторожным, поскольку там нет проверки, что мы, например наш псевдоним складываем с объектом такого же псевдонима

- Переименование - это просто другое имя для типа - они никак не ограничвают поведение, то есть не являются частью системы типов.

Аналог using - это typedef, но более старый

## Настоящие типы.

Пользовательские типы, очевидно, нужны для понимания кода.

День недели "1" - это кто?

### Тип enum (тип перечеслений конечного числа элементов):

https://youtu.be/ZwbcSsul_vA?t=2635

```cpp
enum class weekday_t {MON, TUE, WED, THU, FRI, SAT, SUN};

int main() {
    weekday_t today = weekday_t::MON; // здесь можно не указывать из какого енама - без квадроточия
    // today + 7 выдает ошибку, то есть мы ограничили использования типа
    return 0;
}
```

- enum - действительно новый тип, ведь теперь мы ограничили поведения - он часть системы типов.

Можно enum перегрузить операцию сложения c int спокойненько: https://youtu.be/ZwbcSsul_vA?t=2786

- Для енама можно всегда сделать static_cast<int>(MON) - это вернет 1 - нумерация с 0
  
- Ошибка может случиться при статик касте из инта в енам, потому что там нет проверки на то, какое число мы передаем

Можно самому руками назначить номера внутри енама

### тип Struct.

Структура - вариант перемножения типов, она как декартово произведение множеств тех типов, какие мы атрибуты пишем.

```cpp

struct Position {
    int x, y;
};

int main() {
    Position p;
    p.x = 1;
    p.y = -1;

    p.x += 3;
    // p += 1 - ошибка
}

// Можно определить функцию над структурами:
Position move(Position initial_p, int dist_x, int dist_y) {
    Position result;
    result.x += dist_x;
    result.y += dist_y;
    return result;
}

```
(если методы хотим определить, то лучше уже класс делать)

Операция . - операция обращения к атрибутам

- struct - это тип, он часть системы типов

- Структуры можно инициализировать:

```cpp

int main() {
    Position
        p1 = {1, -1},
        p2 = {.x = 2, .y = 3};
    return 0;
}

```

Можно инициализировать по-умолчанию:

```cpp

struct Position {
    int x = 1, y = -1;
};

```

- Если мы создаем структуру с ссылкой или с const, то мы обязаны инициализировать: https://youtu.be/ZwbcSsul_vA?t=3955

### тип Union.

- Юнион - это объединения множеств типов, то есть, он содержит всего один элемент, он он принадлежит объединению

Это типо один ящик для всего, это одна память выделенная на все типы

- Проблема в том, что мы никак не узнаем, что мы получим при получении значения до его получения

- Начиная с 17 версии плюсов существует тип данных std::variant, https://youtu.be/ZwbcSsul_vA?t=4324

Лучше вообще не использовать union