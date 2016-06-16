# Linearlist manager
Программа работы с линейным списком

## Возможности:
1. Добавление элемента в линейный список
2. Удаление элемента из линейного списка
3. Перестановка первой и второй половины линейного списка
4. Вывод линейного списка
5. Вывод длины линейного списка
6. Очистка линейного списка

## Требования к программному обеспечению:
* ОС: Linux или MacOS
* Компилятор: GNU GCC
* Установленная программа `make`

## Компиляция
1. Запустить терминал
2. Переместиться в корневую папку программы
3. Выполнить: `make`

## Запуск
1. Скомпилировать программу (см. предыдущий пункт)
2. Выполнить в терминале (находясь в корневой папке программы): `./kp8`

## Удаление файлов компиляции и исполняемого файла программы
В процессе компиляции также создаются служебные файлы с расширениями .o и .gch
Для удаления основного исполняемого файла программы файлов компиляции выполнить в терминале: `make clear`

## Работа с программой
Работа программы осуществляется в терминале в интерактивном режиме. Каждая команда состоит из одной буквы и параметров (при наличии). Ввод команды производится с новой строки.

### Команды:
* `a <позиция> <значение>` - добавить элемент в линейный список (если элемент нужно добавить в конец линейного списка, то в качестве параметра `<позиция>` указать `-1`)
* `d <позиция>` - удалить элемент из линейного списка
* `r` - поменять местами первую и вторую половины линейного списка
* `p` - вывести все элементы линейного списка в порядке следования
* `l` - вывести длину линейного спискаъ
* `c` - очистка линейного списка
