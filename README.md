# Задача 2. Таблица
Описание
Нужно написать шаблонный класс для двумерного массива (таблицы). Все ячейки таблицы имеют один и тот же тип данных T.

Требования к классу:

1. Должен быть конструктор, получающий на входе два целых числа — количество строк и столбцов соответственно.
1. Должны быть константная и неконстантная версии оператора [], возвращающего массив, к которому снова можно применить оператор [].
Нужно, чтобы работали конструкции вида:
   * cout << table[i][j];
   * table[i][j] = value;.

1. Должна быть константная функция Size, возвращающая размер таблицы.

---

### Пример правильной работы программы
```
auto test = table<int>(2, 3);
test[0][0] = 4;
std::cout << test[0][0]; // выводит 4
```