Функция рекурсивная, если она определяется через саму себя.

Примеры:
    факториал
    степень

```cpp
int integral_power(int base, int exp)
{
    if (exp == 1)
        return base;
    return base * integral_power(base, exp - 1);    //Рекурсия не хвостовая - просто в качестве примера
}
```

Происходит сброс данных на стек от предыдущего применения функции, и так продолжается пока мы не сможем вычислить безрекурсивно
Короче:
- Разворачиваем стек
- Сворачиваем стек

У рекурсивной функции должна быть база рекурсии - значение, которое мы можем получить без вызова функции внутри себя;

НОД: https://youtu.be/KMPb06itEa4?t=2134

Рекурсивная сумма элементов массива: https://youtu.be/KMPb06itEa4?t=2524

### Разделяй и властвуй:
Суть в том, что есть параллельные вычисления, можно параллельно искать суммы в подмассивах;

В функциональном программировании нет итераций, там есть рекурсии  

Сумма цифр числа: https://youtu.be/KMPb06itEa4?t=3301

Рекурсия работает на стеке, поэтому она может иногда работать хуже итераций,

Для Фибоначчи рекурсия не особо удачна, можно просто запоминать предыдущее значение и делать curr += prev

Чтобы ускрить рекурсию нужно в рекурсии делать return функции самой - хвостовая рекурсия https://youtu.be/KMPb06itEa4?t=3861
(тогда компиллятор оптимизирует процесс)
