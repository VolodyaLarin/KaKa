# Лабораторная работа №2. Преобразования грамматик

Студент ИУ7-22М 03.03.2024 Ларин В.Н. 

## Задание

Постройте программу, которая в качестве входа принимает приведенную КС-грамматику G и
преобразует ее в эквивалентную КС-грамматику G' без левой рекурсии.

**Вариант 2.** Устранение бесполезных символов.

Постройте программу, которая в качестве входа принимает произвольную КС-грамматику G  и
преобразует ее в эквивалентную КС-грамматику G', не содержащую бесполезных символов.


## Анализ работы программы




Дана на вход грамматика:

$[E,F,G,R,T,U] [(,),+,-,a] E$



$E \rightarrow E + T | T$

$F \rightarrow ( E ) | G | a$

$G \rightarrow F | G + R | \epsilon$

$T \rightarrow F | T * F$

$U \rightarrow F$





Здесь имеем прямую рекурсию:
```
E -> E + T
T -> T * F
```

И косвенную:
```
G -> F -> G
```

После устранения левой рекурсии будем иметь:


$[E,E',F,G,G',R,T,T',U] [(,),+,-,a] E$



$E \rightarrow T | T E'$

$E' \rightarrow + T | + T E'$

$F \rightarrow ( E ) | G | a$

$G \rightarrow ( E ) | ( E ) G' | G' | \epsilon | a | a G'$

$G' \rightarrow + R | + R G' | G' | \epsilon$

$T \rightarrow F | F T'$

$T' \rightarrow * F | * F T'$

$U \rightarrow ( E ) |( E ) G' | G' | \epsilon | a | a G'$

Далее удаляем символы, которые не порождают терминалы. В данном случае -- это символ `R`.


$[E,E',F,G,T,U] [(,),+,-,a] E$



$E \rightarrow T | T E'$

$E' \rightarrow + T | + T E'$

$F \rightarrow ( E ) | G | a$

$G \rightarrow ( E ) | \epsilon | a$

$T \rightarrow F$

$U \rightarrow ( E ) |  \epsilon | a$




Удаляем недостижимые символы, в данном случае -- это `U`



$[E,E',F,G,T] [(,),+,-,a] E$



$E \rightarrow T | T E'$

$E' \rightarrow + T | + T E'$

$F \rightarrow ( E ) | G | a$

$G \rightarrow ( E ) | \epsilon | a$

$T \rightarrow F$




## Тестирование 

### Удаление левой рекурсии

<table><thead><tr><td>Вход</td><td>Ожидаемый результат</td><td>Действительный результат</td><td>Комментарий</td></tr></thead><tbody><tr><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$</td><td>

OK
</td></tr>
<tr><td>

$[A] [+,-,a] A$
<br>
$A \rightarrow A + A | A - A | a$
</td><td>

$[A,A'] [+,-,a] A$
<br>
$A \rightarrow a | a A'$
<br>
$A' \rightarrow + A | + A A' | - A | - A A'$
</td><td>

$[A,A'] [+,-,a] A$
<br>
$A \rightarrow a | a A'$
<br>
$A' \rightarrow + A | + A A' | - A | - A A'$</td><td>

OK
</td></tr>
<tr><td>

$[A,B] [a,b] A$
<br>
$A \rightarrow B a | a$
<br>
$B \rightarrow A b | b$
</td><td>

$[A,B,B'] [a,b] A$
<br>
$A \rightarrow B a | a$
<br>
$B \rightarrow a b | a b B' | b | b B'$
<br>
$B' \rightarrow a b | a b B'$
</td><td>

$[A,B,B'] [a,b] A$
<br>
$A \rightarrow B a | a$
<br>
$B \rightarrow a b | a b B' | b | b B'$
<br>
$B' \rightarrow a b | a b B'$</td><td>

OK
</td></tr>
</tbody></table>


### Удаление невыводящих символов

<table><thead><tr><td>Вход</td><td>Ожидаемый результат</td><td>Действительный результат</td><td>Комментарий</td></tr></thead><tbody><tr><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$</td><td>

OK
</td></tr>
<tr><td>

$[A,B] [a,b] A$
<br>
$A \rightarrow A a | B | a$
<br>
$B \rightarrow B b$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$</td><td>

OK
</td></tr>
<tr><td>

$[A,B] [a,b] A$
<br>
$A \rightarrow A a | B | a$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$</td><td>

OK
</td></tr>
</tbody></table>

### Удаление недостижимых символов

<table><thead><tr><td>Вход</td><td>Ожидаемый результат</td><td>Действительный результат</td><td>Комментарий</td></tr></thead><tbody><tr><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$
</td><td>

$[A] [a] A$
<br>
$A \rightarrow a A$</td><td>

OK
</td></tr>
<tr><td>

$[A,B] [a,b] A$
<br>
$A \rightarrow A a | a$
<br>
$B \rightarrow A b$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$
</td><td>

$[A] [a,b] A$
<br>
$A \rightarrow A a | a$</td><td>

OK
</td></tr>
<tr><td>

$[A,B,C] [a,b,c] A$
<br>
$A \rightarrow A a | a$
<br>
$B \rightarrow C b$
<br>
$C \rightarrow B c$
</td><td>

$[A] [a,b,c] A$
<br>
$A \rightarrow A a | a$
</td><td>

$[A] [a,b,c] A$
<br>
$A \rightarrow A a | a$</td><td>

OK
</td></tr>
<tr><td>

$[A,B,C] [a,b,c] A$
<br>
$A \rightarrow A a | B | a$
<br>
$B \rightarrow C b$
<br>
$C \rightarrow B c$
</td><td>

$[A,B,C] [a,b,c] A$
<br>
$A \rightarrow A a | B | a$
<br>
$B \rightarrow C b$
<br>
$C \rightarrow B c$
</td><td>

$[A,B,C] [a,b,c] A$
<br>
$A \rightarrow A a | B | a$
<br>
$B \rightarrow C b$
<br>
$C \rightarrow B c$</td><td>

OK
</td></tr>
</tbody></table>


## Контрольные вопросы

1.	Как может быть определён формальный язык?
    1.	Простым перечислением слов, входящих в данный язык.
    2.	Словами, порождёнными некоторой формальной грамматикой
    3.	Словами, порождёнными регулярным выражением.
    4.	Словами, распознаваемыми некоторым конечным автоматом
2.	Какими характеристиками определяется грамматика?
    1.	$Σ$ – множество терминальных символов
    2.	$N$ – множество нетерминальных символов
    3.	$P$ – множество правил (слева – непустая последовательность терминалов/нетерминалов, содержащая хотя бы один нетерминал, справа – любая последовательность терминалов/нетерминалов)
    4.	$S$ – начальный символ из множества нетерминалов
3.	Дайте описания грамматик по иерархии Хомского. 
    1. Регулярные 
    2. Контекстно-свободные
    3. Контекстно-зависимые
    4. Неограниченные
4.	Какие абстрактные устройства используются для разбора грамматик?
    1.	Распознающие грамматики – устройства (алгоритмы), которым на вход подается цепочка языка, а на выходе устройство печатает «Да», если цепочка принадлежит языку, и «Нет» — иначе.
    2.	Порождающие грамматики - вид устройств, использующийся для порождения цепочек языков по требованию.
5.	Оцените временную и емкостную сложность предложенного вам алгоритма
    1. Алгоритм удаления левой рекурсии
        1.	$O(N^2)$ – временная сложность
        2.	$O(N)$ – ёмкостная сложность
    2. Алгоритм удаления бесполезных символов
       1. $O(N^2)$ – временная сложность
       2. $O(N)$ – ёмкостная сложность
