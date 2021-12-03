# E. Полярные прямоугольники
https://contest.yandex.ru/contest/29396/problems/E/

Ограничение времени

5 секунд

Ограничение памяти

64Mb

#### Ввод

стандартный ввод или input.txt

#### Вывод

стандартный вывод или output.txt

Вася недавно изучил полярную систему координат. А именно, он изучил понятие полярного прямоугольника. Пусть задана стандартная декартова плоскость. Если на ней нарисовать две окружности с центром в начале координат, то область, находящаяся между ними, называется кольцом (на рисунке обозначена синим). Если на ней нарисовать два луча, то область, заметаемая первым лучом при движении ко второму, называется углом (т.е. область между этими двумя лучами, на рисунке обозначена зеленым). Полярным прямоугольником называется пересечение некоторого угла с некоторым кольцом (на рисунке обозначено красным).

![image](img.png)

Задано несколько полярных прямоугольников. Найдите площадь их пересечения. Помните, что пересечение полярных прямоугольников может состоять из нескольких частей!

## Формат ввода

В первой строке вводится целое число N — количество прямоугольников (1 ≤ N ≤ 100 000). Далее в N строках содержится описание прямоугольников. Каждый прямоугольник описывается четверкой действительных чисел r1, r2, φ1, φ2, где r1, r2 обозначают радиусы окружностей, образующих кольцо (r1 < r2), а φ1, φ2 обозначают углы, образованные первым и вторым лучами с осью абсцисс, заданные в радианах. При этом заметается область от первого луча до второго в направлении против часовой стрелки (т.е. возрастания углов), даже в случае, когда φ1 > φ2. Все числа заданы максимум с шестью знаками после десятичной точки. Углы лежат в полуинтервале [0, 2π), а радиусы не превосходят 1e6. Гарантируется, что φ1 ≠ φ2.

## Формат вывода

Выведите единственное число — площадь искомого пересечения. Ответ будет считаться правильным, если его абсолютная или относительная погрешность не будет превышать 1e-6.

### Пример 1

#### Ввод
2\
1 3 0 3\
2 4 1.5 4.5
#### Вывод
3.7500000000

### Пример 2

#### Ввод
2\
1 2 0 3\
1 2 2 1
#### Вывод
3.0000000000