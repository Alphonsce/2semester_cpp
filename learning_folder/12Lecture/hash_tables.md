# Хeширование.

Хеш функция: f : X - > Y, оно всегда не инъективное, так же хочется чтобы получение прообраза было очень сложным, а образа очень простым.

Суть хеша в том, чтобы близкие распределять далеко после отображения - то бишь отображение не непрерывное в плане некоторой метрики

Для того чтобы построить обратное используют просто хеш таблицы

### Алгоритм Рабина - Карпа поиска подстроки

Подстрока это уже как раз когда подряд идут элементы - не просто порядок сохраняется.

Если просто подставлять, то O(nm), поэтому используют хеширование и ищут по хешам

https://youtu.be/fcQ9CRGY6ok?t=2095 - полиномиальный хеш код - позволяет за O(1) делать проверку совпадения хеш кодов для выбранной подстроки длины n и n элементов из большой строки

Тогда полная ассимптотика - вычисления хеш кода для подстроки + O(L).

Так как хеш функция никогда не инъективна, то совпадение хешей не является достаточным условием для равенства строк. После совпадения хешей стоит еще сравнить сами объекты.

## Хеш таблицы как структуры данных.

Идея в том, что хеш(элемента) % размер таблицы - индекс элемента в таблице. В таблице под каждым индексом у нас связный список. 

Чтобы бороться с коллизиями хеширования используется парадигма external chain - то бишь мы кладем элемент всегда на свой индекс, но под каждый индекс у нас связный список. Теперь each location becomes the head of a linked list.

Как добавлять элемент: https://youtu.be/fcQ9CRGY6ok?t=3585 - лекция.

Видос другого чела: https://youtu.be/2Ti5yvumFTU?t=1283